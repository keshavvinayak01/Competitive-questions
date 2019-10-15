#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    int n, m, q;
    cin >> t;
    while(t--){
        cin >> n >> m >> q;
        int matrix[n][m];
        int a,b;
        while(q--){
            cin >> a >> b;
            for(int i = 0; i < m; i++){
                matrix[a-1][i]++;
            }
            for(int i = 0; i < n; i++){
                matrix[i][b-1]++;
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j]%2 != 0) count++;
            }    
        }
        cout << count << endl;
    }
    

    return 0;
}