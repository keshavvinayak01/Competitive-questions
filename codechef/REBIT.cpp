// Apply divide and conquer to solve this problem, compute probabilities of 0, 1, a , A for each expression
// Find combined probabilities and return
#include<bits/stdc++.h>
typedef unsigned long long int lli; 
#define MOD 998244353
using namespace std;

struct probabs {
    lli zero, one, a, A;
};

lli power(lli a, lli n) {
    lli res = 1;
    while(n) {
        if(n & 1)
            res = (res * a) % MOD;
        n >>= 1;
        a = (a * a) % MOD;
    }
    return res;
}

probabs computeSolution(probabs left, probabs right, char op) {
    probabs newProbs;
    if(op == '|') {
        newProbs.zero = (left.zero * right.zero) % MOD;
        newProbs.one = ((left.zero*right.one)%MOD + (left.one*right.zero)%MOD + (left.one*right.one)%MOD + 
                       (left.one*right.a)%MOD + (left.one*right.A)%MOD + (left.a*right.one)%MOD + 
                       (left.a*right.A)%MOD + (left.A*right.one)%MOD + (left.A*right.a)%MOD)%MOD;
        newProbs.a = ((left.zero*right.a)%MOD + (left.a*right.zero)%MOD + (left.a*right.a)%MOD)%MOD;
        newProbs.A = ((left.zero*right.A)%MOD + (left.A*right.zero)%MOD + (left.A*right.A)%MOD)%MOD;
    }
    else if(op == '^') {
        newProbs.zero = ((left.zero*right.zero)%MOD + (left.one*right.one)%MOD + (left.a*right.a)%MOD + 
                        (left.A*right.A)%MOD)%MOD;
        newProbs.one = ((left.zero*right.one)%MOD + (left.one*right.zero)%MOD + (left.a*right.A)%MOD + 
                       (left.A*right.a)%MOD)%MOD;
        newProbs.a = ((left.zero*right.a)%MOD + (left.one*right.A)%MOD + (left.a*right.zero)%MOD + 
                        (left.A*right.one)%MOD)%MOD;
        newProbs.A = ((left.zero*right.A)%MOD + (left.one*right.a)%MOD + (left.a*right.one)%MOD + 
                      (left.A*right.zero)%MOD)%MOD;
    }
    else if(op == '&') {
        newProbs.zero = ((left.zero*right.zero)%MOD + (left.zero*right.one)%MOD + (left.zero*right.a)%MOD + 
                        (left.zero*right.A)%MOD + (left.one*right.zero)%MOD + (left.a*right.zero)%MOD + 
                        (left.a*right.A)%MOD + (left.A*right.zero)%MOD + (left.A*right.a)%MOD)%MOD;
        newProbs.one = (left.one*right.one)%MOD;
        newProbs.a = ((left.one*right.a)%MOD + (left.a*right.one)%MOD + (left.a*right.a)%MOD)%MOD;
        newProbs.A = ((left.one*right.A)%MOD + (left.A*right.one)%MOD + (left.A*right.A)%MOD)%MOD;
    }
    return newProbs;
}

probabs getSolution(string s) {
    stack<char> brackets, operators;
    stack<probabs> temp_res;
    probabs init, first, second, result;
    init.zero = init.one = init.a = init.A = 1;
    char op;
    if(s.size() == 1) return init;
    for(char a : s) {
        if(a == '(') brackets.push(a);
        else if(a == '^' || a == '&' || a == '|') operators.push(a);
        else if(a == '#') temp_res.push(init);
        else {
            op = operators.top(); operators.pop();
            second = temp_res.top(); temp_res.pop();
            first = temp_res.top(); temp_res.pop();
            result = computeSolution(first , second, op);
            temp_res.push(result);
        } 
    }
    return temp_res.top();
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        lli hash_count = 0;
        for(char ch : s) if(ch == '#') hash_count++;
        probabs soln = getSolution(s);
        hash_count = power(power(4, hash_count), MOD -2);
        cout << (soln.zero * hash_count) % MOD << " " << (soln.one * hash_count) % MOD << " "
             << (soln.a * hash_count) % MOD << " " << (soln.A * hash_count) % MOD << endl;           
    }

    return 0;
}