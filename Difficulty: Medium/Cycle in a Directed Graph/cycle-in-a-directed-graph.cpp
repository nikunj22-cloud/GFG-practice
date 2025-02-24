//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int V;
    // Function to detect cycle in a directed graph.
     bool isCyclicDFS( vector<vector<int>>&adj , vector<bool>&visited , vector<bool>&recursion , int u ){
         recursion[u] = true;
         visited[u] = true;
         
         for( int &v : adj[u]){
             if( visited[v]==false && isCyclicDFS(adj , visited , recursion , v)){
                 return true;
             }
             else if( visited[v]==true && recursion[v]==true){
                 return true;
             }
         }
         recursion[u]=false;
         return false;
     }
    bool isCyclic(vector<vector<int>> &adj) {
         V = adj.size();
        // code here
        vector<bool>visited( V , false);
        vector<bool>recursion(V , false);
        
        for( int i = 0 ; i< V ; i++){
            if(!visited[i] && isCyclicDFS(adj , visited , recursion , i)){
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends