//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
public:
    int findFloor(vector<int>& arr, int x) {
        int low = 0;
        int high = arr.size() - 1;
        int floorIndex = -1; // Initialize floor index as -1 (no floor found)
        
        while (low <= high) {
            int mid = low + (high - low) / 2; // Prevents potential overflow
            
            if (arr[mid] == x) {
                floorIndex = mid; // Update floor index
                low = mid + 1; // Search right half for last occurrence
            } else if (arr[mid] < x) {
                floorIndex = mid; // Update floor index
                low = mid + 1; // Search right half for larger candidate
            } else {
                high = mid - 1; // Search left half
            }
        }
        
        return floorIndex;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int x = stoi(ks);
        Solution ob;
        int ans = ob.findFloor(arr, x);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends