#include<iostream>
using namespace std;

bool even_ones(int n) {
    int count = 0;
    while(n) {
        n = (n & (n - 1));
        count++;
    }
    return count % 2 == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, odd_count, even_count, t;
    cin >> t;
    while(t--) {
        even_count = odd_count = 0;
        cin >> n >> q;
        int arr[n], queries[q];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        for(int i = 0 ; i < q ; i++) cin >> queries[i];
        for(int i = 0 ; i < n ; i++) {
            if(even_ones(arr[i])) even_count++;
            else                  odd_count++; 
        }
        for(int i = 0 ; i < q; i++) {
            if(even_ones(queries[i])) printf("%d %d\n", even_count, odd_count);
            else                      printf("%d %d\n", odd_count, even_count);
        }
    }

    return 0;
}