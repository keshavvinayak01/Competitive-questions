#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

int convertFive(int n) {
    int new_number = 0, temp = n, mul = 0;
    while(temp > 0) {
        if(temp%10 == 0) new_number += 5*pow(10, mul);
        else             new_number += (temp%10)*pow(10, mul);
        mul++;
        temp /= 10;
    }
    return new_number;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << convertFive(n) << endl;
    }

    return 0;
}   