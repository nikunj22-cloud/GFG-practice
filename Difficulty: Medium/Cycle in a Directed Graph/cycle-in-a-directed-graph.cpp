//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(vector<vector<int>> &adj) {
        // code here
        //using bfs 
        //same as kahns algo
        int N = adj.size();
      queue<int>q;
      vector<int>indegree(N , 0);
      int count = 0; //to keep track of node
      
      //step1  indegree find kro mtlb u se kha ja skte h mtlb v k pass kitne node 
      for( int u = 0 ;  u<N ; u++){
          for( int &v : adj[u]){
              indegree[v]++;
          }
      }
          //step2 indegree 0 h toh simply push kro then count ko b bdha do
          for( int i =0 ; i<N; i++){
          if(indegree[i] == 0){
              q.push(i);
          }
        }
        //step 3 simple bfs to found count 
        while(!q.empty()){
            int u = q.front();
            q.pop();
            count++;
        
          //ab q se pop krrhe h or pop kr rhe h toh indegre b ghtani pdegi
         for( int &v : adj[u]){
             indegree[v]--;
             if(indegree[v]==0){
                 q.push(v);
             }
         }
        }
         
        
      if(count == N){
          return false;
      }
      return true;
      
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