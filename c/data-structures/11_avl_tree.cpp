#include <iostream>

struct Node {
  int value;
  Node *left;
  Node *right;

  Node (int value) {
    this->value = value;
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

Node* find(Node* root, int value) {
  if (root = nullptr) return nullptr;

  if (value < root->value) {
    return find(root->left, value);
  } 
  
  if (value > root->value) {
    return find(root->right, value);
  } 
      
  return root; 
}

Node* insert(Node* root, int value) {
  if (root == nullptr) {
    return new Node(value);
  } 

  if (value < root->value) {
    root->left = insert(root->left, value);
  } else if (value > root->value) {
    root->right = insert(root->right, value);
  } else {
    return root;
  }

  int balance = balance_factor(root);

  if (balance >= 1 && value < root->left->value) {
    return right_rotate(root);
  }

  if (balance <= -1 && value > root->right->value) {
    return left_rotate(root);
  }

  if (balance >= 1 && value > root->left->value) {
    root->left = left_rotate(root->left);
    return right_rotate(root);
  }

  if (balance <= 1 && value < root->right->value) {
    root->right = right_rotate(root->right);
    return left_rotate(root);
  }

  return root;
}

Node* remove(Node* root, int value) {
  if (root == nullptr) return nullptr;

  if (value < root->value) {
    root->left = remove(root->left, value);
  } else if (value > root->value) {
    root->right = remove(root->right, value);
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

    // find the min value in the right subtree
    Node* min = root->right;
    while (min->left != nullptr) {
      min = min->left;
    }
    root->value = min->value;
    root->right = remove(root->right, min->value);
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

void println(std::string ln) {
  std::cout << ln << '\n';
}

void print(Node* root, std::string prefix = "", bool is_left = true) {
  if (root) {
    std::cout << prefix;
    std::cout << (is_left ? "l: " : "r: ");
    std::cout << root->value << std::endl;

    print(root->left, prefix + (is_left ? "│   " : "    "), true);
    print(root->right, prefix + (is_left ? "│   " : "    "), false);
  }
}

int main() {
  Node* root = nullptr;

  root = insert(root, 10);
  root = insert(root, 20);
  
  println("Balanced AVL Tree: 10 -> 20");
  print(root);

  root = insert(root, 30);

  println("Balanced AVL Tree: 10 -> 20 -> 30");
  print(root);

  println("Balanced AVL Tree: 10 -> 20 -> 30 -> 40");
  root = insert(root, 40);

  print(root);

  root = remove(root, 20);

  println("Balanced AVL Tree: 10 -> 30 -> 40");
  print(root);

  return 0;
}