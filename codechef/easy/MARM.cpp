#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    lli t;
    cin >> t;
    lli n, k, iteration, extra, a, b, repeat;
    while(t--){
        cin >> n >> k;
        lli arr[n];
        for(lli i = 0 ;i < n; i++) cin >> arr[i];
        // The pattern repeats after 3 iterations.
        // First calculate how many iterations actually required.
        iteration = k / n;
        extra = k % n;
        // if k < n, then allow complete calculation
        if(iteration == 0) {
            for(lli j = 0; j < k; j++){
                    arr[j%n]^=arr[n-1-(j%n)];
                }
            if(k/(3*n) >=1 && n%2) arr[n/2]=0;
            for(lli i = 0 ; i < n; i++) cout << arr[i] << " ";
            cout << endl;
        }
        // else, take modulus with 3 and allow calculation k % 3 times.
        else {
            repeat = iteration % 3;
            while(repeat > 0) {
                for(lli j = 0; j < n; j++){
                    arr[j%n]^=arr[n-1-(j%n)];
                }
                repeat--;
            }
            // K isn't necessary a multiple of n. After k % 3 iterations, allow the extra iterations.
            if(extra > 0) {
                for(lli j = 0; j < extra; j++){
                   arr[j%n]^=arr[n-1-(j%n)];
                }
            }
            if(k/(3*n) >=1 && n%2) arr[n/2]=0;
            for(lli i = 0 ; i < n; i++) cout << arr[i] << " ";
            cout << endl;
        }
    }
    return 0;
}