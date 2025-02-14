//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};


// } Driver Code Ends


#include <vector>
using namespace std;

// Definition for a binary tree node.
// struct Node {
//     int data;
//     Node* left;
//     Node* right;
//     Node(int val) : data(val), left(nullptr), right(nullptr) {}
// };

class Solution {
public:
    vector<int> leftView(Node* root) {
        vector<int> result;
        recursion(root, 0, result); // Call the recursive helper function
        return result;
    }

private:
    void recursion(Node* root, int level, vector<int>& result) {
        if (root == nullptr) return; // Base case: if the node is null, return

        // If the current level is equal to the size of the result vector,
        // it means this is the first node at this level, so add it to the result.
        if (level == result.size()) {
            result.push_back(root->data);
        }

        // Recur for the left and right subtrees
        recursion(root->left, level + 1, result);  // Traverse the left subtree
        recursion(root->right, level + 1, result); // Traverse the right subtree
    }
};

//{ Driver Code Starts.

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
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

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> vec = ob.leftView(root);
        if (vec.size() == 0) {
            cout << "[]";
        }
        for (int x : vec)
            cout << x << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends