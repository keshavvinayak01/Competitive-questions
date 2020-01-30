#include<bits/stdc++.h>
using namespace std;

bool less_than_previous(int index, int* a){
    int start;
    if(index < 5){
        start = 0;
    }
    else{
        start = index - 5;
    }
    for(int i = start; i < index; i++){
        if(a[index] >= a[i]){
            return false;
        }
    }
    return true;
}


int main(){
    int t;
    cin >> t;
    int n, count;
    while(t--){
        cin >> n;
        int a[n];
        for(int i = 0 ; i < n; i++) cin >> a[i];
        count = 1;
        for(int i = 1; i < n; i++){
            if(less_than_previous(i, a)){
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}