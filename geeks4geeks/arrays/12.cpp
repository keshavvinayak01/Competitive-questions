#include <bits/stdc++.h>
using namespace std;

int convertFive(int n);

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        convertFive(n);
    }
}// } Driver Code Ends


/*you are required to complete this method*/
int convertFive(int n) {
    int newNum = 0, digit = 1, temp = n;
    while(temp > 0) {
        if(temp%10 == 0) {
            newNum += digit*5;
        }
        newNum += (temp%10)*digit;
        temp = temp/10;
        digit *= 10;    
    }
    // cout << newNum << endl;
    return newNum;
}