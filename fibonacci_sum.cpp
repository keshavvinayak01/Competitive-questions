#include<iostream>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void multiply(int A[2][2],int M[2][2]){

	int firstValue = (((A[0][0]%MOD) * (M[0][0]%MOD))%MOD + ((A[0][1]%MOD) * (M[1][0]%MOD))%MOD)%MOD;
	int secondValue = (((A[0][0]%MOD) * (M[0][1]%MOD))%MOD + ((A[0][1]%MOD) * (M[1][1]%MOD))%MOD)%MOD;
	int thirdValue = (((A[1][0]%MOD) * (M[0][0]%MOD))%MOD + ((A[1][1]%MOD) * (M[1][0]%MOD))%MOD)%MOD;
	int fourthValue = (((A[1][0]%MOD) * (M[0][1]%MOD))%MOD + ((A[1][1]%MOD) * (M[1][1]%MOD))%MOD)%MOD;

	A[0][0] = firstValue;
	A[0][1] = secondValue;
	A[1][0] = thirdValue;
	A[1][1] = fourthValue;
	
}
void power(int A[2][2],int n){
	if(n==1){
		return;
	}
	power(A,n/2);
	multiply(A,A);
	if(n%2 !=0){
		int F[2][2] = {{1,1},{1,0}};
		multiply(A,F);
	}
}
int getFibonacci(int n){
	if(n==0 || n==1){
		return n;
	}
	int A[2][2] = {{1,1},{1,0}};
	power(A,n-1);
	return A[0][0];
}


int main(){
	int a, b;
	cin >> a >> b;
	cout << (getFibonacci(b + 2) - getFibonacci(a + 1))%MOD <<endl;
	return 0;
}