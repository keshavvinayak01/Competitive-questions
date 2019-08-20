#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int temp[n];
        for(int i=0; i<n;i++)
            cin >> temp[i];
        for(int i=1 ; i < n; i++){
            if((temp[i] - temp[i-1] == -1)){
                swap(temp[i], temp[i-1]);
            }
        }
        string ans = "Yes";
        for(int i=0 ; i < n - 1; i++){
            if(temp[i] > temp[i+1]){
                ans = "No";
                break;
            }
        }
        cout << ans << endl;
        
    }
	return 0;
}
