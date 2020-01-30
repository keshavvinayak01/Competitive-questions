#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ** image = new int*[n];
    int ** rotated = new int*[n];
    for(int i = 0 ; i < n ; i++) {
        image[i] = new int[n];
        rotated[i] = new int[n];
        for(int j = 0 ; j < n ; j++){
            cin >> image[i][j];
        }
    }
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            rotated[n-j-1][i] = image[i][j];
        }
    }
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) cout << rotated[i][j] << " ";
        cout << endl;
    }
    return 0;
} 