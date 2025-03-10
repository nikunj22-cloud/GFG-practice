//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
     vector<string>result;
      string temp;
   bool isSafe( int i , int j , int n){
            return ( i>= 0 && i<n && j>=0 && j<n);
        }
        void solve( vector<vector<int>> &mat , int i , int j ,int n){
            if(!isSafe( i , j , n) || mat[i][j]==0){
                return ;
            }
            if( i == n-1 && j==n-1){
                result.push_back(temp);
                return ;
            }
             
             mat[i][j] = 0;
            temp.push_back('U');
            solve( mat , i-1 , j , n);
            temp.pop_back();
            
            temp.push_back('L');
            solve( mat , i, j-1 , n);
            temp.pop_back();
            
            temp.push_back('R');
            solve( mat , i , j+1 , n);
            temp.pop_back();
            
            temp.push_back('D');
            solve( mat , i+1 , j , n);
            temp.pop_back();
            mat[i][j] = 1;
            
        }
    vector<string> findPath(vector<vector<int>> &mat) {
         int n = mat.size();
        solve( mat , 0 , 0 , n);
        // code here
        return result;
       
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends