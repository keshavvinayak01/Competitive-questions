#include<bits/stdc++.h>
using namespace std;

int longestBitonicSubarray(int *input, int n) {
	int *lis=new int[n];
    int *lds=new int[n];
    lis[0]=1;
        for(int i=1;i<n;i++)
        {
            lis[i]=1;
            for(int j=i-1;j>=0;j--)
            {
              if(input[j]>input[i])
                  continue;
              int posans=lis[j]+1;
              if(posans>lis[i])
                  lis[i]=posans;
                
            }
        }
      for(int i=0;i<n;i++)
          lds[i]=1;
        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-1;j>i;j--)
            {
                if(input[j]>input[i])
                    continue;
                int pos=lds[j]+1;
                if(pos>lds[i])
                    lds[i]=pos;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if((lis[i]+lds[i]-1)>ans)
                ans=lis[i]+lds[i]-1;
        }
        return ans;
     	
 	}

int main(){

    int n;
    cin >> n;
    int* input = new int[n];
    for(int i=0; i < n;i++){
        cin >> input[i ];
    }
    int ans = longestBitonicSubarray(input, n);
    cout << ans << endl;
    delete[] input;
}