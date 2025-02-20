//{ Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include "bits/stdc++.h"
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* BST Node
struct Node 
{
    int key;
    struct Node *left;
    struct Node *right;
    
    Node(int x){
        key = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution
{
public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        if (root == NULL) return;

        // If the key is found
        if (root->key == key) {
            // Find the predecessor (maximum value in the left subtree)
            if (root->left != NULL) {
                Node* temp = root->left;
                while (temp->right != NULL)
                    temp = temp->right;
                pre = temp;
            }   //pre 

            // Find the successor (minimum value in the right subtree)
            if (root->right != NULL) {
                Node* temp = root->right;
                while (temp->left != NULL)
                    temp = temp->left;
                suc = temp;
            }
            return;
        }

        // If the key is smaller than the root's key, go to the left subtree
        if (root->key > key) {
            suc = root; // Current node could be the successor
            findPreSuc(root->left, pre, suc, key);
        }
        // If the key is larger than the root's key, go to the right subtree
        else {
            pre = root; // Current node could be the predecessor
            findPreSuc(root->right, pre, suc, key);
        }
    }
};



//{ Driver Code Starts.

Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}
// Driver program to test above functions
int main() {
   
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, s);
        int k = stoi(s);
        Node *pre=NULL,*succ=NULL;
        Solution ob;
        ob.findPreSuc(root,pre,succ,k);
        (pre!=NULL)?cout<<pre->key:cout<<-1;
        cout<<" ";
        (succ!=NULL)?cout<<succ->key:cout<<-1;
        cout<<endl;
        // inOrderTraversal(root);
   
cout << "~" << "\n";
}
   return 0;
}
// } Driver Code Ends