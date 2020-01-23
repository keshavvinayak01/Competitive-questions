#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;


lli computeXOR(lli n) 
{ 
    // Modulus operator are expensive on most of the  
    // computers. n & 3 will be equivalent to n % 4.    
  
    switch(n & 3) // n % 4  
    { 
    case 0: return n;     // if n is multiple of 4 
    case 1: return 1;     // If n % 4 gives remainder 1   
    case 2: return n + 1; // If n % 4 gives remainder 2     
    case 3: return 0;     // If n % 4 gives remainder 3   
    } 
    return 0;
} 
  
lli findXOR(lli l, lli r)  { 
    return (computeXOR(l - 1) ^ computeXOR(r)); 
} 

int main() {
    lli t, a, b;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        lli sum = 0;
        for(int i = a ; i <= b; i++) {
            sum += findXOR(a, i) % MOD;
            sum = sum % MOD;
        }
        cout << sum;
    }
    return 0;
}