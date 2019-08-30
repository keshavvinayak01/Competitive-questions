#include<bits/stdc++.h>
using namespace std;

int min_cost(int **input, int si, int sj, int ei, int ej, int** output){
    if(si == ei && sj == ej){
        return input[ei][ej];
    }
    if(si > ei || sj > ej){
        return INT_MAX;
    }
    if(output[si][sj] > -1){
        return output[si][sj];
    }
    int option1 = min_cost(input, si+1, sj, ei, ej);
    int option2 = min_cost(input, si+1, sj+1, ei, ej);
    int option3 = min_cost(input, si, sj+1, ei, ej);
    output[si][sj] = input[si][sj] + min(option1, min(option2, option3))
    return input[si][sj] + min(option1, min(option2, option3));
}

int min_cost_iterative(int **input, int m, int n){
    int** dp = new int*[m];
    for(int i=0; i < n; i++){
        dp[i] = new int[n];
    }
    dp[m-1][n-1] = input[m-1][n-1];
    for(int i = m-2; i>=0; i--)
        dp[i][n-1] = dp[i+1][n-1] + input[i][n-1];
    for(int j = n - 2; j >=0 ;j--)
        dp[m-1][j] = dp[m-1][j+1] + input[m-1][j];

    for(int i = m - 2; i >= 0 ; i--){
        for(int j = n - 2; j >=0; j--){
            dp[i][j] = input[i][j] + min(dp[i+1][j], min(dp[i+1][j+1], dp[i][j+1]));
        }
    }
    int ans =  dp[0][0];
    delete[] dp[0];
    delete[] dp[1];
    delete[] dp[2];
    delete[] dp;
    return ans;
}

int main(){
    int **grid = new int*[3];
    int **output = new int*[3];
    for(int i=0;i<3;i++){
        grid[i] = new int[3];
        output[i] = new int[3];
    }
    for(int i=0; i < 3; i++)
        for(int j=0;j<3;j++)
            cin >> grid[i][j];
    cout << min_cost(grid, 0, 0, 2, 2, output) << endl;
    delete [] input[0];
    delete [] input[1];
    delete [] input[2];
    delete [] input;
    return 0;
}