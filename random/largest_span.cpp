#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

int LCS(string A, string B, int m, int n, int sum1, int sum2) {
    if(m < 0 || n < 0) {
        if(sum1 == sum2) return sum1;
        else return 0;
    }
    int option1 = LCS(A, B, m-1, n-1, sum1 + (A[m] - '0'), sum2 + (B[n] - '0'));
    int option2 = LCS(A, B, m-1, n-1, A[m], B[n]);
    cout << max(option1, option2) << endl;
    return max(option1, option2);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    string A = "01101011010";
    string B = "11101001110";
    cout << LCS(A, B, sizeof(A)/sizeof(A[0]), sizeof(B)/sizeof(B[0]), 0, 0) << endl;
    return 0;
}