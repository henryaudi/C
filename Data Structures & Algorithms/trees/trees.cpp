#include <iostream>

/**
 * @brief Node class for Binary Search Tree
 */
class Node {
public:
    int   value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

/**
 * @brief Binary Search Tree class
 */
class BinarySearchTree {
private:
    Node* root;

public:
    BinarySearchTree() : root(nullptr) {}

    BinarySearchTree(int value) {
        this->root = new Node(value);
    }

    bool insert(int value);
    bool contains(int value);

    friend std::ostream& operator<<(std::ostream& os, const BinarySearchTree& bst);
};

bool BinarySearchTree::contains(int value) {
    if (root == nullptr) {
        return false;
    }

    Node* temp = this->root;
    while (temp != nullptr) {
        if (temp->value == value) {
            return true;
        }

        if (temp->value > value) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    return false;
}

bool BinarySearchTree::insert(int value) {
    Node* newNode = new Node(value);
    if (root == nullptr) {
        root = newNode;
        return true;
    }

    Node* temp = this->root;
    while (true) {
        if (temp->value == value) {
            delete newNode;  // Avoid memory leak
            return false;    // No duplicates allowed
        }

        if (value < temp->value) {
            if (temp->left == nullptr) {
                temp->left = newNode;
                return true;
            }
            temp = temp->left;
        } else {
            if (temp->right == nullptr) {
                temp->right = newNode;
                return true;
            }
            temp = temp->right;
        }
    }
}

std::ostream& operator<<(std::ostream& os, const BinarySearchTree& bst) {
    // This is a placeholder for the actual implementation of printing the tree
    os << "Binary Search Tree with root value: " << (bst.root ? bst.root->value : -1);
    return os;
}

int main() {
    BinarySearchTree* myBST = new BinarySearchTree();
    std::cout << *myBST << std::endl;
    delete myBST;
    return 0;
}