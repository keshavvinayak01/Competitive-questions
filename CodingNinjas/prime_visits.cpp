#include<bits/stdc++.h>
using namespace std;

void getSieveAnswers(int* answers, bool* prime) {
    prime[1] = false;
    prime[0] = false;
    for(int p = 2; p*p <= 100000 ; p++) {
        if(prime[p]) {
            for(int i = p*p; i <= 100000; i += p) {
                prime[i] = false;
            }
        }        
    }
    int counter = 0;
    for(int i = 0; i <= 100000; i++) {
        if(prime[i]) counter++;
        answers[i] = counter;
    }
}

int calcSieveAnswer(int a, int b, int* answers, bool* prime) {
    if(prime[a]) return(answers[b] - answers[a] + 1);
    else return answers[b] - answers[a];
    
}

int main() {
    int n;
    cin >> n;
    bool* prime = new bool[1000001];
    for(int i = 0 ; i <= 100000; i++) prime[i] = true;
    int* answers = new int[1000001];
    getSieveAnswers(answers, prime);
    while(n--) {
        int a, b;
        cin >> a >> b;
        cout << calcSieveAnswer(a, b, answers, prime) << endl;
    }
    return 0;
}