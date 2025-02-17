//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    return new Node(val);
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after splitting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
public:
    // Traverse the left boundary (excluding leaf nodes)
    void traverseLeft(Node* root, vector<int>& ans) {
        if (!root || (!root->left && !root->right)) {
            return; // Stop at leaf nodes
        }
        ans.push_back(root->data); // Add current node to the result
        if (root->left) {
            traverseLeft(root->left, ans); // Traverse left subtree
        } else {
            traverseLeft(root->right, ans); // Traverse right subtree if left is null
        }
    }

    // Traverse all leaf nodes
    void traverseLeaf(Node* root, vector<int>& ans) {
        if (!root) {
            return; // Base case
        }
        if (!root->left && !root->right) {
            ans.push_back(root->data); // Add leaf node to the result
            return;
        }
        traverseLeaf(root->left, ans); // Traverse left subtree
        traverseLeaf(root->right, ans); // Traverse right subtree
    }

    // Traverse the right boundary (excluding leaf nodes) in reverse order
    void traverseRight(Node* root, vector<int>& ans) {
        if (!root || (!root->left && !root->right)) {
            return; // Stop at leaf nodes
        }
        if (root->right) {
            traverseRight(root->right, ans); // Traverse right subtree
        } else {
            traverseRight(root->left, ans); // Traverse left subtree if right is null
        }
        ans.push_back(root->data);// Add current node to the result (reverse order)
    }

    vector<int> boundaryTraversal(Node* root) {
        vector<int> ans;
        if (!root) {
            return ans; // Empty tree
        }

        // Step 1: Add the root node
        ans.push_back(root->data);

        // Step 2: Traverse the left boundary (excluding leaf nodes)
        traverseLeft(root->left, ans);

        // Step 3: Traverse all leaf nodes
        traverseLeaf(root->left, ans); // Left subtree leaves
        traverseLeaf(root->right, ans); // Right subtree leaves

        // Step 4: Traverse the right boundary (excluding leaf nodes) in reverse order
        traverseRight(root->right, ans);

        return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function */
int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s, ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> res = ob.boundaryTraversal(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends