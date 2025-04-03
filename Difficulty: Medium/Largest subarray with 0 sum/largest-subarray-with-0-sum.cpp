//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        unordered_map<int , int>mp;
        int n = arr.size();
        int maxlen = 0;
        int maxsum  = 0;
         mp[0] = -1 ;
         
         
         for( int i = 0 ; i< n ; i++){
            
             maxsum += arr[i];
             
             if( mp.find(maxsum) != mp.end()){
                 maxlen = max( maxlen , i - mp[maxsum]);
             }
             else{
             mp[maxsum] = i;
             }
         }
         return maxlen;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.maxLen(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends