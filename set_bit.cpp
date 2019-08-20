#include<bits/stdc++.h>
using namespace std;

int turnOnIthBit(int n, int i){
	// return n | (1 << i);
	int result =  n | (1 << i);
	return result ^ (1 << i);
}

int returnFirstSetBit(int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    for(int i=0; i < 32; i++){
        if(n & (1 << i))
            return i;
    }
    // if(n)
}
int turnOffFirstSetBit(int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
	cout << returnFirstSetBit(n) << endl;
    return n & (1 << returnFirstSetBit(n));

}

int getBitSize(int n){
	int count = 1;
	while(n > 1){
		n = n >> 1;
		count += 1;
	}
	return count;
}

int clear_all_bits_msb(int n, int k){
	int x =  1 <<  k;
	x -= 1;
	cout << "x : " << x << endl;
	return n & x;
}


int main(){
	int n, k;
	cin >> n >> k;
	// cout << turnOnIthBit(n, i);
	// cout << turnOffFirstSetBit(n);
	cout << clear_all_bits_msb(n, k) << endl;
	return 0;
}