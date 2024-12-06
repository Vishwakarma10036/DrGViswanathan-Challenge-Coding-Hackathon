/*
Single File Programming Question
Level order traversal in spiral form
Complete the function to find spiral order traversal of a tree. For below tree, function should return 1, 2, 3, 4, 5, 6, 7.
1
2
I
3
7
6
5
4

Example 1:
Input:
1
--
3
2

Output:1
3
2
I
Example 2:

Input:
10
/
20
30
/
40
60

Input format:
The first line of the input is the space-separated node values.

Output format: 
The output is the space-separated integers representing the node values after a spiral order traversal.

Code constraints:
0 <= Number of nodes <= 105
0 <= Data of a node <= 105
Sample test cases:

Input 1: 
1 3 2

Output 1:
1 3 2

Input 2:
10
20
30
40
50
60
70

Output 2:
10
20
30
40
50
60 
70
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to build a binary tree from space-separated input.
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return NULL;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Add left child
        if (nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        // Add right child
        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

// Function to perform spiral level order traversal.
vector<int> spiralOrderTraversal(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    stack<TreeNode*> s1; // Stack for right-to-left
    stack<TreeNode*> s2; // Stack for left-to-right

    s1.push(root);

    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            TreeNode* node = s1.top();
            s1.pop();
            result.push_back(node->val);

            if (node->right) s2.push(node->right);
            if (node->left) s2.push(node->left);
        }

        while (!s2.empty()) {
            TreeNode* node = s2.top();
            s2.pop();
            result.push_back(node->val);

            if (node->left) s1.push(node->left);
            if (node->right) s1.push(node->right);
        }
    }
    return result;
}

int main() {
    string input;
    getline(cin, input);
    stringstream ss(input);
    vector<int> nodes;
    int val;
    while (ss >> val) {
        nodes.push_back(val);
    }

    TreeNode* root = buildTree(nodes);
    vector<int> result = spiralOrderTraversal(root);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}