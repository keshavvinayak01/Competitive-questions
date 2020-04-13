// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
// 	long long int test;
// 	cin>>test;
// 	for(long long int x=0;x<test;x++)
// 	{
// 		long long int  N;
// 		cin>>N;
// 		vector <long long int> V(N);
// 		vector <long long  int> V1;
// 		V1.push_back(-1);
// 		for(long long int y=0;y<N;y++)
// 		{
// 			cin>>V[y];
// 			if(V[y]%2==0)
// 			{
// 				V1.push_back(y);
// 			} 
// 		}
// 		V1.push_back(N);
// 		long long int sum=0,result=0;
// 		for(long long int y=1;y<V1.size()-1;y++)
// 		{
// 			if(V[V1[y]]%4!=0 )
// 			{
// 		    long long int m=V1[y]-V1[y-1]-1;
// 			long long int n=V1[y+1]-V1[y]-1;
// 			long long int p=m+n+1;
// 			result=(p*(p+1)/2)-(m*(m+1)/2)-(n*(n+1)/2);
// 				sum=sum+result;
// 			}
// 		}
// 		cout<<(N*(N+1)/2)-sum<<endl;
// 	}
// 	return 0;
// }

#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli t, n, ans, a, b, c;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<lli> v(n), v1;
        v1.push_back(-1);
        for(int i = 0 ; i < n ; i++) {
            cin >> v[i];
            if(v[i] % 2 == 0) v1.push_back(i);
        }
        v1.push_back(n);
        ans = 0;
        for(int i = 1 ; i < v1.size() - 1; i++) {
            if(v[v1[i]] % 4 != 0) {
                a = ((v1[i+1] - v1[i] - 1)*(v1[i+1] - v1[i]))/2;
                b = (v1[i] - v1[i-1] - 1)*(v1[i] - v1[i-1])/2;
                c = (v1[i+1] - v1[i-1] - 1)*(v1[i+1] - v1[i-1])/2;
                ans += c - a - b;
            }
        }
        cout << (n*(n+1)/2 - ans) << endl;
    }
    return 0;
}