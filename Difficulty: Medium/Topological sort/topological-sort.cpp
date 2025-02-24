//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int V;
    
    // Function to return list containing vertices in Topological order.
    void usingDFS(vector<vector<int>>& adj, int u, vector<bool>& visited, stack<int>& st) {
        visited[u] = true;

        for (int &v : adj[u]) {
            if (!visited[v]) {
                usingDFS(adj, v, visited, st);  // Recursive call
            }
        }

        st.push(u); // Push current node after visiting all children
    }

    vector<int> topologicalSort(vector<vector<int>>& adj) {
        V = adj.size();  // Set number of vertices
        vector<bool> visited(V, false);
        stack<int> st;
        vector<int> result;

        // Perform DFS for each unvisited node
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                usingDFS(adj, i, visited, st);
            }
        }

        // Pop elements from stack to form topological order
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
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