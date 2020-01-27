#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long int
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
    
        int km[n],fuel[n],dp[2000];
    
        for(int i=0; i<n; i++) cin>>km[i];
        for(int i=0; i<n; i++) cin>>fuel[i];
    
        for(int i=0; i<=1000; i++) dp[i] = mod;
    
        for(int i=0; i<n; i++){
            dp[fuel[i]] = 1;
        }
    
        for(int i=0; i<n; i++){
            for(int j=0; j<1001; j++){
                if(dp[j]!=mod){
                    if(j+fuel[i]<1001){
                        dp[j+fuel[i]] = min(dp[j+fuel[i]], dp[j]+1);
                    }
                }
            }
        }
    
        ll ans = 0;
        for(int i=0; i<n; i++){
            ans+=dp[2*km[i]];
        }
    
        cout<<ans<<'\n';
    }
    return 0;
}