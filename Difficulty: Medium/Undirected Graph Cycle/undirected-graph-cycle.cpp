//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
     bool DFS( vector<vector<int>>&adj , int u , vector<bool>&visited ,  int parent){
           visited[u] = true;
        
              for( int &v : adj[u]){
                  if( v == parent)continue;
                  if(visited[v])return true;
                  if(DFS(adj , v , visited , u ))return true;
              } 
          
          return false;
     }
    bool isCycle(vector<vector<int>>& adj) {
       int  V = adj.size();
        // Code here
        vector<bool>visited(V , false);
           
         
         for( int i = 0 ; i<V; i++){
             if(!visited[i] && DFS(adj , i , visited , -1)){
             return true;
             }
         }
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends