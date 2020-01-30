#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void eulerPhi(int n, int* phi){

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
}

ll lcm_sum(int k, int* phi) {
    ll temp = k;
    ll sum_lcm = 1 + k*phi[k];
    int product = 1;
    for(int i = 2; i*i <=temp ; i++) {
        int power = 0;
        while(k%i == 0) {
            k /= i;
            power++;
            product *= i;
            sum_lcm += product*phi[product];
        }
    }
    return ((sum_lcm + 1)*temp)/2;
}


int main() {
    int n;
    cin >> n;
	int* phi = new int[1000001];
    eulerPhi(1000000, phi);
    cout << lcm_sum(n, phi) << endl;
    return 0;
}