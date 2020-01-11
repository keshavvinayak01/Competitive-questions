#include<bits/stdc++.h>
using namespace std;

int modExp(int a, int b, int c) {
    if(a == 0) return 0;
    if(b == 0) return 1;

    long ans;
    if((b%2) == 0) {
        long smallAns = modExp(a, b/2, c);
        ans = (smallAns*smallAns)%c;
    }
    else {
        long smallAns = modExp(a, b-1, c);
        ans = (ans%c);
        ans = (ans*smallAns)%c;
    }
    return int((ans + c)%c);
}

int main() {
    //  2**10 % 5;
    cout << modExp(2, 10, 5);

    return 0;
}