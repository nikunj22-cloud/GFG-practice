//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public: 
    void merge(vector<int>& arr, int l, int m, int r) {
        int l1 = m - l + 1;
        int l2 = r - m;
        
        vector<int> L(l1), R(l2);
        
        for (int i = 0; i < l1; i++) {
            L[i] = arr[l + i];
        }
        for (int j = 0; j < l2; j++) {
            R[j] = arr[m + 1 + j];
        }
        
        int i = 0, j = 0, k = l;
        
        while (i < l1 && j < l2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        
        while (i < l1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        
        while (j < l2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    
    void mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r) {
            return;
        }
        
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
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
        Solution obj;
        obj.mergeSort(arr, 0, arr.size() - 1);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends