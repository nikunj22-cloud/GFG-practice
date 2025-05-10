//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        sort(A.begin() , A.end() , greater<int>());
        sort(B.begin() , B.end() , greater<int>());
        
        priority_queue<pair<int , pair<int , int>>>maxHeap;
        set<pair<int , int>>visited;
        maxHeap.push({A[0] + B[0] ,{ 0 ,0 }});
        visited.insert({0 ,0});
        vector<int>result;
        
        while( K-- && !maxHeap.empty()){
            auto current = maxHeap.top();
            maxHeap.pop();
            
       
            
            int sum = current.first;
            int i = current.second.first;
            int j = current.second.second;
                 result.push_back(sum);
            
            if( i + 1 < N && visited.find({i+1 , j}) == visited.end()){
                maxHeap.push( {A[i+1] + B[j] , { i+1 , j }});
                visited.insert({i+1 , j});
            }
             if( j + 1 < N && visited.find({i , j+1}) == visited.end()){
                maxHeap.push( {A[i] + B[j+1] , { i , j+1 }});
                visited.insert({i , j+1});
            }
        }
        return result;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends