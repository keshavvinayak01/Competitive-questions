#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    lli max_count, t, n, temp;
    cin >> t;
    while(t--) {
        max_count = INT_MIN;
        cin >> n;
        vector<lli> counts(1000001, 0);

        while(n--) {
            cin >> temp;
            max_count = max(counts[temp], max_count);
            for(int i = 1 ; i <= sqrt(temp); i++) {
                if(temp % i == 0) {
                    counts[i]++;
                    if(i*i != temp) counts[temp/i]++;
                }
            }
        }
        cout << max_count << endl;
    }

    return 0;
}