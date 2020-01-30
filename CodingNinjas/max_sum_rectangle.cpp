#include<bits/stdc++.h>
using namespace std;

void fill_sums(int *sums, int n){
    for(int i=0;i < n ; i++)
        sums[i] = 0;
}

int main(){
    int n,m;
    cin >> n >> m;
    int a[n][m];
    for(int i=0; i<n; i++)
        for(int j = 0 ; j < m; j++)
            cin >> a[i][j];
    int sums[n];
    fill_sums(sums, n);
    int max_sum = INT_MIN;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            sums[j] = a[j][i];
            if(sums[j] > max_sum) max_sum = sums[j];
        }
        for(int j = i+1; j < m; j++){
            for(int k = 0 ; k < n ; k++){
                sums[k] += a[k][j];
            }
            int start_sum = 0;
            for(int i=0; i < n ; i++){
                start_sum += sums[i];
                if(start_sum > max_sum) max_sum = start_sum;
                if(start_sum < 0) start_sum = 0;
                
            }
            }
        }
    cout << max_sum << endl;
    return 0;
}