#include <bits/stdc++.h>
using namespace std;

int main()
{
    int budget, n;
    while(cin >> budget >> n){
        
        if(budget == 0 && n == 0)
            break;
        
        int fee[n], fun[n];
        for(int i=0; i<n; i++)
            cin >> fee[i] >> fun[i];
        
        int memo[n+1][budget+1];
        
        for(int i=0; i<=n; i++){
            for(int w=0; w<=budget; w++){
                
                if(i == 0 || w == 0)
                    memo[i][w] = 0;
                else if(fee[i-1] > w)
                    memo[i][w] = memo[i-1][w];
                else
                    memo[i][w] = max(fun[i-1] + memo[i-1][w-fee[i-1]], memo[i-1][w]);
            }
        }
        
        int totalFees;
        for(totalFees=0; totalFees<=budget; totalFees++)
            if(memo[n][totalFees] == memo[n][budget])
                break;
      
        
        cout << totalFees <<" "<< memo[n][budget] << endl;
        
    }
    
    return 0;
}
