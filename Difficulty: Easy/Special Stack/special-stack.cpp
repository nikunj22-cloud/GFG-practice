//{ Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	
cout << "~" << "\n";
}
}
// } Driver Code Ends

#include<bits/stdc++.h>
void push(stack<int>& s, int a) {
    s.push(a);
}

// Check if the stack is full (assuming max size `n`)
bool isFull(stack<int>& s, int n) {
    return s.size() == n;  // Returns true if stack size reaches max `n`
}

// Check if the stack is empty
bool isEmpty(stack<int>& s) {
    return s.empty();  // Corrected: Must return the boolean result
}

// Pop an element from the stack
int pop(stack<int>& s) {
    if (s.empty()) return -1; // Handle underflow case
    int j = s.top();
    s.pop();
    return j;
}



int getMin(stack<int>& s) {
    if (s.empty()) return -1; // Handle empty stack case

    stack<int> temp = s; // Create a copy of s
    int minElement = temp.top();
    temp.pop();

    while (!temp.empty()) {
        minElement = min(minElement, temp.top()); // Compare min with temp's top
        temp.pop();
    }

    return minElement; // Return the minimum element
}
