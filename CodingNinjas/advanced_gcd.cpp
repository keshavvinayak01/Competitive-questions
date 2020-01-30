/*
Varun explained its friend Sanchit the algorithm of Euclides to calculate the GCD of two numbers.
Then Sanchit implements the algorithm
int gcd(int a, int b)
{

    if (b==0)
    return a;
    else
    return gcd(b,a%b);
}
and challenges to Varun to calculate gcd of two integers, one is a little integer and other 
integer has 250 digits.
Your task is to help Varun an efficient code for the challenge of Sanchit.
*/

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b);

int reduceLarge(int a, string b) {
    int current = 0;
    for(int i = 0 ; i < b.length(); i++) {
        current = ((current * 10) % a + (b[i] - '0') % a) % a;
    }
    return gcd(a, current);
}

int gcd(int a, int b) {
    if(b == 0) return a;

    return gcd(b, a%b);
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        int a;
        string b;
        cin >> a >> b;
        cout << reduceLarge(a, b) << endl;
    }


    return 0;
}