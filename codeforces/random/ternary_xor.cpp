#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;
 
 
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n], arr1[n], arr2[n];
        string arr_in;
        cin >> arr_in;
        for(int i = 0 ; i < n ; i++) arr[i] = arr_in[i] - '0';
        lli curr_a = 0, curr_b = 0;
        for(int i = 0; i < n ; i++) {
            if(arr[i] == 2) {
                if(curr_a == curr_b) {
                    arr1[i] = 1; arr2[i] = 1;
                    curr_a += pow(2, i);
                    curr_b = curr_a;
                }
                else if(curr_a > curr_b) {
                    arr1[i] = 0;
                    arr2[i] = 2;
                    curr_b += pow(2, i+1);
                }
                else {
                    arr1[i] = 2;
                    arr2[i] = 0;
                    curr_a += pow(2, i+1);
                }
            }
            else if(arr[i] == 1) {
                if(curr_a > curr_b) {
                    arr1[i] = 0;
                    arr2[i] = 1;
                    curr_b += pow(2, i);
                }
                else {
                    arr1[i] = 1;
                    arr2[i] = 0;
                    curr_a += pow(2, i);
                }
            }
            else {
                arr1[i] = arr2[i] = 0;
            }
        }
        for(int i = 0 ; i < n ; i++) cout << arr1[i];
        cout << endl;
        for(int i = 0 ; i < n ; i++) cout << arr2[i];
        cout << endl; 
    }
 
    return 0;
}