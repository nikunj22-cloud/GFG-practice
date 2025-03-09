//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
        
     void SubSet( vector<int>& arr , vector<int>& subset , int idx , int sum  , int n){
         if( idx == n){
             subset.push_back(sum);
             return ;
         }
         //isme koi target tk phcuhna nhi diya h isliye hm ko alg se push  or pop ki jrurt ni h
         SubSet( arr , subset , idx+1 , sum+arr[idx] , n );
         //not pick
         SubSet(arr , subset , idx+1 , sum , n);
         
     }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int>subset;
        int sum ;
        int idx;
        int n = arr.size();
        SubSet( arr , subset , 0 , 0 , n);
        return subset;
    }
};


//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input

    while (t--) {
        vector<int> inputArray;
        string inputLine;

        // Input format: first number n followed by the array elements
        getline(cin, inputLine);
        stringstream inputStream(inputLine);
        int num;
        while (inputStream >> num) {
            inputArray.push_back(num); // Read the array elements from input string
        }

        Solution solutionObject;
        vector<int> result = solutionObject.subsetSums(inputArray);
        sort(result.begin(), result.end());

        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout
            << endl
            << "~\n"; // Print results in list format with new line after each test case
    }

    return 0;
}

// } Driver Code Ends