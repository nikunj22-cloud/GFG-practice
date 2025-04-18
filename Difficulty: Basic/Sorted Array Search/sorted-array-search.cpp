//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Recursive binary search helper
    bool binary(vector<int>& arr, int k, int l, int h) {
        // Base case: not found
        if (l > h) {
            return false;
        }

        int mid = l + (h - l) / 2;

        if (arr[mid] == k) {
            return true;
        } else if (arr[mid] > k) {
            return binary(arr, k, l, mid - 1); // Search in left half
        } else {
            return binary(arr, k, mid + 1, h); // Search in right half
        }
    }

    // Main function
    bool searchInSorted(vector<int>& arr, int k) {
        int l = 0;
        int h = arr.size() - 1;
        return binary(arr, k, l, h);
    }
};



//{ Driver Code Starts.

int main(void) {

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

        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << (ob.searchInSorted(arr, k) ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends