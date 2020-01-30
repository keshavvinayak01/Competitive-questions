#include<bits/stdc++.h>
using namespace std;

bool zeroInCol(int **arr, int col, int row){
    for(int i = 0 ; i < row; i++){
        if(arr[i][col] == 0)
            return true;
    }
    return false;
}

int findMaxSquareWithAllZeros( int **arr, int row, int col){
    int *colSums = new int[row];
    int max_ans = 0;
    for(int i=0; i < col-1; i++){
        for(int k = 0 ; k < row; k++){
            colSums[k] = arr[k][i];
        }
        for(int j = i+1; j < col; j++){
            if(!zeroInCol(arr, i, row)){
                break;
            }
            for(int k = 0 ; k < row; k++){
                colSums[k] += arr[k][j];
            }
            int zcount = 0;
            for(int k = 0 ; k < row; k++){
                if(colSums[k] != 0) {
                    zcount = 0;
                }
                else if(colSums[k] == 0){
                    zcount++;
                }
                if(zcount > max_ans && j - i + 1 == zcount){
                    max_ans = zcount;
                }
            }
        }
    }
    if(max_ans == 0){
        for(int i = 0 ; i < row ; i++){
            if(arr[i][col-1] == 0){
                return 1;
            }
        }
    }
    return max_ans;
}


int main(){
    int n,k;
    cin >> n >> k;
    int** arr = new int*[n];
    for(int i=0; i < n; i++)
        arr[i] = new int[k];
    for(int i=0; i < n; i++)
        for(int j=0 ; j < k ; j++)
            cin >> arr[i][j];

    cout << findMaxSquareWithAllZeros(arr, n, k) << endl;
    return 0;
}