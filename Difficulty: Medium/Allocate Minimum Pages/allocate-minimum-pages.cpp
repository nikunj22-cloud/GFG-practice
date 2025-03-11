//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    bool isPossible(vector<int>& arr, int k, int mid) {
        int student = 1, pageSum = 0;
         
        for (int i = 0; i < arr.size(); i++) {
            if (pageSum + arr[i] <= mid) {
                pageSum += arr[i];
            } else {
                student++;
                if (student > k) return false;
                pageSum = arr[i]; // Start new allocation
            }
        }
        return true;
    }

    int findPages(vector<int> &arr, int k) {
        if (k > arr.size()) return -1; // Not enough books for students

        int s = *max_element(arr.begin(), arr.end()); // Lower bound (largest book)because at least one book toh pdni pdegi
        int e = accumulate(arr.begin(), arr.end(), 0); // Upper bound (sum of all pages)
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (isPossible(arr, k, mid)) {
                ans = mid;
                e = mid - 1; // Minimize maximum pages
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends