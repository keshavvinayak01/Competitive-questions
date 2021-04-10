// { Driver Code Starts
// C++ program to evaluate value of a postfix expression
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    // The main function that returns value of a given postfix expression
    int evalExp(int a, int b, char s) {
        if(s == '+') return a + b;
        else if(s == '*') return a * b;
        else if(s == '-') return a - b;
        else if(s == '/') return a / b;
    }
    
    int evaluatePostfix(string s) {
        stack<int> result;
        int a, b;
        int n = s.length();
        for(int i = 0 ; i < n ; i++) {
            if(s[i] - '0' >= 0 && s[i] - '0' <= 9)
                result.push(s[i] - '0');
            else {
                b = result.top();
                result.pop();
                a = result.top();
                result.pop();
                result.push(evalExp(a, b, s[i]));
            }
        }
        return result.top();
        // Your code here
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends