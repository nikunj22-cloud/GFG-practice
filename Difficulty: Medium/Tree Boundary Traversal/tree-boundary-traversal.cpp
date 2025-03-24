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
    vector<int> boundaryTraversal(Node *root) {
        vector<int> result;
        if (!root) return result; // Agar tree khali hai
        
        // Root ko add karo (except agar woh leaf na ho)
        result.push_back(root->data);
        
        // Left boundary (except leaves)
        addLeftBoundary(root->left, result);
        
        // Leaves (left aur right dono subtree se)
        addLeaves(root->left, result);
        addLeaves(root->right, result);
        
        // Right boundary (except leaves)
        addRightBoundary(root->right, result);
        
        return result;
    }
    
    // Left boundary ke nodes add karne ke liye
    void addLeftBoundary(Node* root, vector<int>& result) {
        Node* curr = root;
        while (curr) {
            // Agar leaf nahi hai toh add karo
            if (!isLeaf(curr)) {
                result.push_back(curr->data);
            }
            // Left mein jao, agar left nahi toh right
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    
    // Right boundary ke nodes add karne ke liye
    void addRightBoundary(Node* root, vector<int>& result) {
        vector<int> temp; // Temporary storage kyunki bottom-up chahiye
        Node* curr = root;
        while (curr) {
            if (!isLeaf(curr)) {
                temp.push_back(curr->data);
            }
            // Right mein jao, agar right nahi toh left
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
        // Reverse order mein result mein add karo
        for (int i = temp.size() - 1; i >= 0; i--) {
            result.push_back(temp[i]);
        }
    }
    
    // Leaves add karne ke liye
    void addLeaves(Node* root, vector<int>& result) {
        if (!root) return;
        if (isLeaf(root)) {
            result.push_back(root->data);
            return;
        }
        addLeaves(root->left, result);
        addLeaves(root->right, result);
    }
    
    // Check karo ki node leaf hai ya nahi
    bool isLeaf(Node* node) {
        return (node && !node->left && !node->right);
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