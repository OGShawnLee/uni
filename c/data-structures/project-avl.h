#include <iostream>
#include <functional>

struct Node {
  size_t id;
  int grade;
  Node *left;
  Node *right;

  Node (int value, size_t identifier) {
    this->grade = value;
    this->id = identifier;
    left = right = nullptr;
  }
};

// (n1) -> (n2) -> (n3) 
Node* right_rotate(Node* n1) {
  Node* n2 = n1->left;
  Node* n3 = n2->right;

  n2->right = n1;
  n1->left = n3;

  // (n1)  <- (n2) -> (n3)

  return n2;
}

// (n3) <- (n2) <- (n1) 
Node* left_rotate(Node* n1) {
  Node* n2 = n1->right;
  Node* n3 = n2->left;

  n2->left = n1;
  n1->right = n3;

  // (n3) <- (n2) -> (n1) 
  
  return n2;
}

// length of the tree
int len(Node* node) {
  if (node == nullptr) return -1;
  return 1 + len(node->left) + len(node->right);
}

int height(Node* node) {
  if (node == nullptr) return -1;
  return 1 + std::max(height(node->left), height(node->right));
}

int balance_factor(Node* node) {
  if (node == nullptr) return 0;
  return height(node->left) - height(node->right);
}

Node* find(Node* root, int grade) {
  if (root == nullptr) return nullptr;

  if (grade < root->grade) {
    return find(root->left, grade);
  } 
  
  if (grade > root->grade) {
    return find(root->right, grade);
  } 
      
  return root; 
}

Node* insert(Node* root, int grade, size_t id) {
  if (root == nullptr) {
    return new Node(grade, id);
  } 

  if (grade < root->grade) {
    root->left = insert(root->left, grade, id);
  } else if (grade > root->grade) {
    root->right = insert(root->right, grade, id);
  } else {
    // return root;
    root->right = insert(root->right, grade, id);
  }


  int balance = balance_factor(root);
  
  if (balance > 1 && grade < root->left->grade) {
    return right_rotate(root);
  }

  if (balance < -1 && grade > root->right->grade) {
    return left_rotate(root);
  }

  if (balance > 1 && grade > root->left->grade) {
    root->left = left_rotate(root->left);
    return right_rotate(root);
  }

  if (balance < -1 && grade < root->right->grade) {
    root->right = right_rotate(root->right);
    return left_rotate(root);
  }

  return root;
}

Node* remove(Node* root, int grade) {
  if (root == nullptr) return nullptr;

  if (grade < root->grade) {
    root->left = remove(root->left, grade);
  } else if (grade > root->grade) {
    root->right = remove(root->right, grade);
  } else {
    if (root->left == nullptr) {
      Node* right = root->right;
      delete root;
      return right;
    }

    if (root->right == nullptr) {
      Node* left = root->left;
      delete root;
      return left;
    }

    // find the min grade in the right subtree
    Node* min = root->right;
    while (min->left != nullptr) {
      min = min->left;
    }
    root->grade = min->grade;
    root->right = remove(root->right, min->grade);
  }

  int balance = balance_factor(root);

  if (balance == 2 && balance_factor(root->left) >= 0) {
    return right_rotate(root);
  }

  if (balance == 2 && balance_factor(root->left) == -1) {
    root->left = left_rotate(root->left);
    return right_rotate(root);
  }

  if (balance == -2 && balance_factor(root->right) <= 0) {
    return left_rotate(root);
  }

  if (balance == -2 && balance_factor(root->right) == 1) {
    root->right = right_rotate(root->right);
    return left_rotate(root);
  }

  return root;
}

void each_pre_order(Node* root, std::function<void(Node*)> fn) {
  if (root == nullptr) return;

  fn(root);
  each_pre_order(root->left, fn);
  each_pre_order(root->right, fn);
}

void println(std::string ln) {
  std::cout << ln << '\n';
}

void print(Node* root, std::string prefix = "", bool is_left = true) {
  if (root) {
    std::cout << prefix;
    std::cout << (is_left ? "l: " : "r: ");
    std::cout << root->grade << std::endl;

    print(root->left, prefix + (is_left ? "│   " : "    "), true);
    print(root->right, prefix + (is_left ? "│   " : "    "), false);
  }
}

void print(std::string ln) {
  std::cout << ln;
}
