#include<iostream>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void multiply(ll A[2][2],ll M[2][2]){

	int firstValue = (((A[0][0]%MOD) * (M[0][0]%MOD))%MOD + ((A[0][1]%MOD) * (M[1][0]%MOD))%MOD)%MOD;
	int secondValue = (((A[0][0]%MOD) * (M[0][1]%MOD))%MOD + ((A[0][1]%MOD) * (M[1][1]%MOD))%MOD)%MOD;
	int thirdValue = (((A[1][0]%MOD) * (M[0][0]%MOD))%MOD + ((A[1][1]%MOD) * (M[1][0]%MOD))%MOD)%MOD;
	int fourthValue = (((A[1][0]%MOD) * (M[0][1]%MOD))%MOD + ((A[1][1]%MOD) * (M[1][1]%MOD))%MOD)%MOD;

	A[0][0] = firstValue;
	A[0][1] = secondValue;
	A[1][0] = thirdValue;
	A[1][1] = fourthValue;
	
}
void power(ll A[2][2],ll n){
	if(n==1){
		return;
	}
	power(A,n/2);
	multiply(A,A);
	if(n%2 !=0){
		ll F[2][2] = {{2,2},{1,0}};
		multiply(A,F);
	}
}
ll getElement(ll n){
	if(n==0 || n==1){
		return n;
	}
    if(n == 2) return 3;
	ll A[2][2] = {{2,2},{1,0}};
	power(A,n-2);
	return ((3*(A[0][0] % MOD)) % MOD + A[0][1] % MOD) % MOD;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        cout << getElement(n) << endl;
    }
    return 0;
}