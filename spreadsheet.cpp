#include<bits/stdc++.h>
using namespace std;

void print_arr(int** solution, int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n; j++)
            cout << solution[i][j] << " ";
        cout << endl;
    }
}

void print_dp(int *arr, int n){
    for(int i = 0; i < n ;i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int n, m;
    cin >> n >> m;
    int **arr = new int *[n];
    int **solution = new int*[n];
    for(int i = 0; i < n; i++){
        arr[i] = new int[m];
        solution[i] = new int[n];
    }
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            cin >>arr[i][j];
    int q;
    cin >> q;
    int queries[q][2];
    for(int i = 0 ; i < q; i++){
        cin >>queries[i][0] >> queries[i][1];
    }
    int *dp = new int[m];
    for(int i = 0; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            solution[i][j] = 0;

    
    for(int i = 0 ; i < n ; i++){
        solution[i][i] = 1;
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < m ; j++){
            dp[j] = arr[i][j];
        }
        for(int j = i+1; j < n; j++){
            for(int k = 0 ; k < m ; k++){
                if(arr[j][k] >= dp[k] && solution[i][j-1] == 1){
                    solution[i][j] = 1;
                    dp[k] = arr[j][k];
                    // print_arr(solution, n, m);
                }
                else{
                    dp[k] = INT_MAX;
                }
            }
        }
    }
    for(int i = 0 ; i < q; i++){
        if(solution[queries[i][0] - 1][queries[i][1] - 1] == 1)
            cout << "Yes"
        else cout << 
    }
    return 0;
}