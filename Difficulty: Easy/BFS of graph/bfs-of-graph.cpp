//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   int V;
     void BFS( vector<vector<int>>&adj , int u , vector<bool>&visited , vector<int>&result){
         queue<int>q;
         q.push(u);
         visited[u] = true;
         result.push_back(u);
         while(!q.empty()){
             int u = q.front();
             q.pop();
             
             for( int & v : adj[u]){
                 if(!visited[v]){
                     q.push(v);
                     visited[v]  = true;
                     result.push_back(v);
                 }
             }
         }
     }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
         V = adj.size();
        vector<bool>visited(V , false);
        vector<int>result;
        BFS(adj , 0 , visited , result);
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends