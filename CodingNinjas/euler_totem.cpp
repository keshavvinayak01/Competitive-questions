#include<iostream>
using namespace std;


void eulerPhi(int n){

	int phi[n+1];

	for(int i=1;i<=n;i++){
		phi[i] = i;
	}

	for(int i=2;i<=n;i++){
		if(phi[i] == i){
			phi[i] = i-1;
			for(int j=2*i;j<=n;j+=i){
				phi[j] = (phi[j]*(i-1))/i;
			}
		}
	}

	for(int i=1;i<=n;i++){
		cout << "Euler Totient Phi For " << i << "Is :" << phi[i]<<endl;
	}

}
int main(){

	eulerPhi(5);
	return 0;
}