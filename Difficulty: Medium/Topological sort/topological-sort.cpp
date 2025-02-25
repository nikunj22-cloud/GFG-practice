//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here 
        //using bfs kahns algorithm
        //first step -indegree nikalo
        queue<int>q;
        int N = adj.size();
        vector<int>indegree(N , 0);
        vector<int>result;
        for( int u = 0 ; u<adj.size() ; u++){
            for( auto  &v : adj[u]){
                indegree[v]++; //indegree bdha di 
            }
        }
        //step2 find indegree and push in to the que
        //which degree is 0
        
        for( int i = 0 ; i<adj.size() ; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        //step3 perform bfs
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            //bhai ab pop krliya h mtlb woh result h toh usko simply result m push kro
            result.push_back(u);
          
        
        //indegree bhi toh ghtani pdegi joh node unse judi hui h unki 
        for( int &v : adj[u]){
           indegree[v]--;
            if( indegree[v]==0){
            q.push(v);
        }
      }
        
      }
        return result;
    }
    
};


//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends