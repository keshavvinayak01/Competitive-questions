// Apply divide and conquer to solve this problem, compute probabilities of 0, 1, a , A for each expression
// Find combined probabilities and return
#include<bits/stdc++.h>
typedef unsigned long long int lli; 
using namespace std;

struct probabs {
    lli zero, one, a, A;
};

struct Triplet {
    lli x, y, gcd;
};

lli normalGCD(lli a, lli b) {
    if(b == 0) return a;
    else return normalGCD(b, a%b);
}

lli gcdExtended(lli a, lli b, lli *x, lli *y); 
lli modInverse(lli a, lli m) 
{ 
    lli x, y; 
    lli g = gcdExtended(a, m, &x, &y); 
    lli res = (x%m + m) % m; 
    return res; 
} 
  
lli gcdExtended(lli a, lli b, lli *x, lli *y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    lli x1, y1; 
    lli gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 

probabs combineSolution(probabs left, probabs right, char op) {
    probabs newProbs;
    if(op == '|') {
        newProbs.zero = left.zero * right.zero;
        newProbs.one = left.zero*right.one + left.one*right.zero + left.one*right.one + left.one*right.a +
                       left.one*right.A + left.a*right.one + left.a*right.A + left.A*right.one +
                       left.A*right.a;
        newProbs.a = left.zero*right.a + left.a*right.zero + left.a*right.a;
        newProbs.A = left.zero*right.A + left.A*right.zero + left.A*right.A;
    }
    else if(op == '^') {
        newProbs.zero = left.zero*right.zero + left.one*right.one + left.a*right.a + left.A*right.A;
        newProbs.one = left.zero*right.one + left.one*right.zero + left.a*right.A + left.A*right.a;
        newProbs.a = left.zero*right.a + left.one*right.A + left.a*right.zero + left.A*right.one;
        newProbs.A = left.zero*right.A + left.one*right.a + left.a*right.one + left.A*right.zero;
    }
    else if(op == '&') {
        newProbs.zero = left.zero*right.zero + left.zero*right.one + left.zero*right.a + left.zero*right.A +
                        left.one*right.zero + left.a*right.zero + left.a*right.A + left.A*right.zero +
                        left.A*right.a;
        newProbs.one = left.one*right.one;
        newProbs.a = left.one*right.a + left.a*right.one + left.a*right.a;
        newProbs.A = left.one*right.A + left.A*right.one + left.A*right.A;
    }
    return newProbs;
}

probabs getSolution(string s, lli start, lli end) {
    if(end == start) {
        probabs newProb = {1, 1, 1, 1};
        return newProb;
    }
    else {
        lli mid = (start + end)/2;
        if(s[mid] == '#') mid--;
        probabs leftSoln = getSolution(s, start, mid-1);
        probabs rightSoln = getSolution(s, mid + 1, end);
        return combineSolution(leftSoln, rightSoln, s[mid]);
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli MOD = 998244353;
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        
        s.erase(remove(s.begin(), s.end(), ')'), s.end());
        s.erase(remove(s.begin(), s.end(), '('), s.end());

        probabs solution = getSolution(s, 0, s.length()-1);
        lli q = solution.zero + solution.one + solution.a + solution.A;

        lli c = normalGCD(solution.zero ,q);
        solution.zero /= c;
        lli temp_q = q/c;
        lli ans1 = ((solution.zero % MOD) * (modInverse(temp_q, MOD)%MOD))%MOD;

        c = normalGCD(solution.one ,q);
        solution.one /= c;
        temp_q = q/c;
        lli ans2 = ((solution.one % MOD) * (modInverse(temp_q, MOD)%MOD))%MOD;

        c = normalGCD(solution.a ,q);
        solution.a /= c;
        temp_q = q/c;
        lli ans3 = ((solution.a % MOD) * (modInverse(temp_q, MOD)%MOD))%MOD;
        
        c = normalGCD(solution.A ,q);
        solution.A /= c;
        temp_q = q/c;
        lli ans4 = ((solution.A % MOD) * (modInverse(temp_q, MOD)%MOD))%MOD;
        cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << endl;
    }

    return 0;
}