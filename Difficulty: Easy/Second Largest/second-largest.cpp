//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        priority_queue<int>max_heap;
        
        for( int i =  0 ; i<arr.size() ; i++){
          max_heap.push(arr[i]);
        }
        int largest = max_heap.top();
        max_heap.pop();
    
    while( !max_heap.empty()){
        if( max_heap.top() != largest){ //duplicate avoid krne k liye
            return max_heap.top();
        }
        max_heap.pop();
    }
    return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends