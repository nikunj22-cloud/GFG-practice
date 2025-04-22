//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        // Your code goes here
        int i = 1;
        int j = n;
        int ans = 0;
        if( n == 0 || n == 1){
            return n;
        }
        while( i<= j){
            int mid = i + (j-i)/2;
            if(mid*mid == n){
                return mid;
            }
            else if( mid*mid < n){
                ans = mid;
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends