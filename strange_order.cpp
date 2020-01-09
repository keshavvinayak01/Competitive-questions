#include<bits/stdc++.h>
using namespace std;

bool reverseComp(int a, int b) {
    return a > b;
}

vector<int> getPrimeFactors(int n) {
    vector<int> ans;
    int temp = n;
    for(int i = 2; i*i <= temp ; i++) {
        if(n == 1) break;
        if(n%i == 0) ans.push_back(i);
        while(n%i == 0) {
            n /= i;
        }
    }
    if(ans.size() == 0) ans.push_back(temp);    
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> currAns;
    bool* marked = new bool[n+1];
    for(int i = n ; i >= 1 ; i--) {
        if(!marked[i]) {
            vector<int> temp_ans;
            vector<int> primeFactors = getPrimeFactors(i);
            for(int j = 0 ; j < primeFactors.size(); j++) {
                for(int k = primeFactors[j]; k <= n; k += primeFactors[j]) {
                    marked[k] = true;
                    temp_ans.push_back(k);
                }                 
            }
            sort(temp_ans.begin(), temp_ans.end(), reverseComp);
            for(int l = 0 ; l < temp_ans.size(); l++) currAns.push_back(temp_ans[l]);
        }
    }

    int* counts = new int[n+1];

    for(int i = 0 ; i < currAns.size(); i++){
        if(counts[currAns[i]] == 0) {
            cout << currAns[i] << " ";
            counts[currAns[i]]++;
        }
    }
    cout << 1 << endl;
    return 0;
}