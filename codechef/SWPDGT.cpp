#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    int max_sum;
    cin >> t;
    while(t--) {
        int a, b, first, second, option1, option2;
        cin >> a >> b;
        max_sum = a + b;
        if(a/10 == 0 && b / 10 == 0) {
            cout << max_sum << endl;
        }
        else if(a/10 == 0 || b / 10 == 0) {
            first = min(a, b);
            second = max(a, b);
            option1 = first*10 + second % 10 + second/10;
            option2 = second + first;
            cout << max(option1, option2) << endl;
        }
        else{
            option1 = (b %10)*10 + a % 10 + (b/10)*10 + a/10;
            option2 = (a %10)*10 + b % 10 + (a/10)*10 + b/10;
            cout << max(option1, max(option2, max_sum)) << endl;
        }
        
    }

    return 0;
}

// sum1 = a + b;
// sum2 = (a/10)*10 + b % 10 + (b/10)*10 + a % 10;
// sum3 = (b%10)*10 + (a % 10) + b/10 + (a/10)*10; 