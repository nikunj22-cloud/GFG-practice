//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(const vector<int>& arr) {
    for (int num : arr)
        printf("%d ", num);
    printf("\n");
}


// } Driver Code Ends

class Solution {
  public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
    if (low < high) {
        // Partition index
        int pi = partition(arr, low, high);

        // Recursively sort left and right
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }

    }

  public:
    // Function that takes last element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    int partition(vector<int>& arr, int low, int high) {
        // code here
        int i = low-1;
       
        int n = arr.size();
        int pivot = arr[high];
        for( int j = low ; j<=high-1; j++){
            if( arr[j] < pivot){
                i++;
             swap(arr[j] , arr[i]);    
            }

        }
        swap( arr[i+1]  , arr[high]);
        
        return (i+1);
    }
};
// Best case: O(n log n)

// Average case: O(n log n)

// Worst case: O(n²) (when the smallest or largest element is always chosen as pivot)

//{ Driver Code Starts.

int main() {

    int T;
    scanf("%d", &T);
    getchar(); // to consume newline after T

    while (T--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        ob.quickSort(arr, 0, arr.size() - 1);
        printArray(arr);
    }

    return 0;
}

// } Driver Code Ends