#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        char arr[n][n];
        for(int i = 0 ; i < n ; i++) 
            for(int j = 0 ; j < n ; j++)
                cin >> arr[i][j];

        /* comment this out!!! */
        // cout << "\n";



        pair<int, int> first, second;
        first.first = -1;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(arr[i][j] == '*'){
                    if(first.first == -1) {
                        first.first = i;
                        first.second = j;
                    }
                    else {
                        second.first = i;
                        second.second = j;
                        break;
                    }
                }
            }
        }
        
        // printf("first : %d, %d\n", first.first, first.second);
        // printf("second : %d, %d\n", second.first, second.second);

        // Same row
        if(first.first == second.first) {
            if(first.first + 1 < n) {
                arr[first.first+1][first.second] = '*';
                arr[first.first+1][second.second] = '*';
            }
            else {
                arr[first.first-1][first.second] = '*';
                arr[first.first-1][second.second] = '*';
            }   
        }
        // Same column
        else if(first.second == second.second) {
            if(first.second + 1 < n) {
                arr[first.first][first.second + 1] = '*';
                arr[second.first][first.second + 1] = '*';
            }
            else {
                arr[first.first][first.second - 1] = '*';
                arr[second.first][first.second - 1] = '*';
            }   
        }
        // Different row and column
        else{
            arr[first.first][second.second] = '*';
            arr[second.first][first.second] = '*';    
        }
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++)
                cout << arr[i][j];
            cout << "\n";
        }
    }
    return 0;
}