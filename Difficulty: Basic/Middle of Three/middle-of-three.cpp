//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int middle(int a, int b, int c) {
        // If 'b' is the middle element
        if ((a < b && b < c) || (c < b && b < a)) 
            return b;

        // If 'a' is the middle element
        else if ((b < a && a < c) || (c < a && a < b)) 
            return a;

        // Otherwise, 'c' is the middle element
        return c;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int A, B, C;
        cin >> A >> B >> C;
        Solution ob;
        cout << ob.middle(A, B, C) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends