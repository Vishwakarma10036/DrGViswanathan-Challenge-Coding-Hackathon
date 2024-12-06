/*
Single File Programming Question
Problem Statement
You are working on a critical customer database system for a large e-commerce platform.
The database stores customer information, like their unique customer IDs, in a binary tree structure. Ensuring data integrity is paramount, as duplicate customer IDs can lead to serious data inconsistencies and operational issues.
Your task is to develop a program that checks whether the binary tree containing customer IDs has any duplicate values. Detecting duplicates is essential to maintain the accuracy of customer records.

Input format:
The first line of input consists of an integer representing the value of the root node.
For each node in the tree, there are two integers, Left child data: an integer representing the value of the left child node. Use -1 to indicate no left child.
Right child data: an integer representing the value of the right child node. Use -1 to indicate no right child.

Output format:
Print "Yes" if there are any duplicate customer IDs in the binary tree.
Otherwise, print "No".

Code constraints:
1 <= Number of nodes in the binary tree <= 100 1 <= Customer ID (node value) <= 100
Sample test cases:

Input 1:
1
1
-1
-1
-1
-1
Output 1: Yes

Input 2:
5
3
7
2
8
-1
-1
-1
-1
-1
-1
Output 2: No
*/

// You are using GCC

#include <iostream>
#include <unordered_set>

// Define the structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to count the number of nodes in the binary tree
int nodeCount(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + nodeCount(root->left) + nodeCount(root->right);
}

// Function to create a new binary tree node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to build the binary tree from input
Node* buildBinaryTree() {
    int data;
    std::cin >> data;
    if (data == -1) {
        return nullptr;
    }
    Node* root = createNode(data);
    root->left = buildBinaryTree();
    root->right = buildBinaryTree();
    return root;
}

// Function to check if a binary tree has duplicate values
bool hasDuplicateValues(Node* root, std::unordered_set<int>& seen) {
    if (root == nullptr) {
        return false;
    }
    if (seen.find(root->data) != seen.end()) {
        return true;
    }
    seen.insert(root->data);
    return hasDuplicateValues(root->left, seen) || hasDuplicateValues(root->right, seen);
}

bool hasDuplicateValues(Node* root) {
    std::unordered_set<int> seen;
    return hasDuplicateValues(root, seen);
}

int main() {
    Node* root = nullptr;
    root = buildBinaryTree();
    if (hasDuplicateValues(root)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    return 0;
}