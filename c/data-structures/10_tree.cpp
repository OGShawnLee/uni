#include <iostream>
#include <functional>

void println(std::string ln) {
  std::cout << ln << std::endl;
}

struct Node {
  int data;
  Node *left = nullptr;
  Node *right = nullptr;

  explicit Node(int data) {
    this->data = data;
  }
};

enum Order {
    PRE_ORDER,
    IN_ORDER,
    POST_ORDER
};

// Prototypes

void cut(Node* &root);

Node* find(Node* root, enum Order order, int data);

void insert(Node* &root, int data);

bool has_value(Node* root, int data);

void remove(Node* &root, int data);

void use_traversal(Node* root, enum Order order, std::function<void(Node*)> callback);

void cut(Node* &root) {
    use_traversal(root, Order::POST_ORDER, [](Node* node) {
        delete node;
    });

    root = nullptr;
}

Node* find(Node* root, enum Order order, int data) {
    if (root == nullptr) return nullptr;

    bool match = root->data == data;

    if (order == Order::PRE_ORDER && match) return root;
    
    Node *left = find(root->left, order, data);
    if (left != nullptr) return left;

    if (order == Order::IN_ORDER && match) return root;

    Node *right = find(root->right, order, data);
    if (right != nullptr) return right;

    if (order == Order::POST_ORDER && match) return root;

    return nullptr;
}

void insert(Node* &root, int data) {
    if (root == nullptr) {
        root = new Node(data);
    } else if (data > root->data) {
        insert(root->right, data);
    } else {
        insert(root->left, data);
    }
}

bool has_value(Node* root, int data) {
    if (root == nullptr) return false;

    if (root->data == data) return true;

    if (data > root->data) {
        return has_value(root->right, data);
    } else {
        return has_value(root->left, data);
    }
}

void remove(Node* &root, int data) {
    if (root == nullptr) return;

    if (data > root->data) {
        remove(root->right, data);
    } else if (data < root->data) {
        remove(root->left, data);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        } else if (root->left == nullptr) {
            Node *father = root;
            root = root->right;
            delete father;
        } else if (root->right == nullptr) {
            Node *father = root;
            root = root->left;
            delete father;
        } else {
            Node *father = root->right;

            while (father->left != nullptr) {
                father = father->left;
            }

            root->data = father->data;
            remove(root->right, father->data);
        }
    
    }
}

void use_traversal(Node* root, enum Order order, std::function<void(Node*)> callback) {
    if (root == nullptr) return;

    if (order == Order::IN_ORDER) {
        use_traversal(root->left, order, callback);
        callback(root);
        use_traversal(root->right, order, callback);
    } else if (order == Order::PRE_ORDER) {
        callback(root);
        use_traversal(root->left, order, callback);
        use_traversal(root->right, order, callback);
    } else {
        use_traversal(root->left, order, callback);
        use_traversal(root->right, order, callback);
        callback(root);
    } 
}

int main() {
    Node *root = new Node(0);

    insert(root, 1);
    insert(root, 3);
    insert(root, 5);
    insert(root, 2);
    insert(root, 6);
    insert(root, 4);
    insert(root, -10);
    insert(root, -20);

    println("\n -> In Order\n");
    use_traversal(root, Order::IN_ORDER, [](Node* node) {
        printf("data: %d\n", node->data);
    });

    println("\n -> Pre Order\n");
    use_traversal(root, Order::PRE_ORDER, [](Node* node) {
        printf("data: %d\n", node->data);
    });

    println("\n -> Post Order\n");
    use_traversal(root, Order::POST_ORDER, [](Node* node) {
        printf("data: %d\n", node->data);
    });

    cut(root);

    return 0;
}