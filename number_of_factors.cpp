/*
    A number is called n-factorful if it has exactly n distinct prime factors. 
    Given positive integers a, b, and n, your task is to find the number of integers 
    between a and b, inclusive, that are n-factorful. We consider 1 to be 0-factorful.
*/

#include<bits/stdc++.h>
using namespace std;

struct Query{
    int a, b, n;
};

int main() {
    int t;
    cin >> t;
    vector<Query> queries;
    for(int i = 0 ; i < t ; i++) {
        Query x;
        cin >> x.a >> x.b >> x.n;
        queries.push_back(x);
    }

    int primeFactors[1000001];
    for(int i = 0 ; i <= 1000000; i++) primeFactors[i] = 0;
    // Do for 2 first
    for(int j = 2 ; j <= 1000000; j += 2) {
        primeFactors[j]++; 
    }
    for(int i = 3; i*i <= 1000000; i += 2) {
        if(primeFactors[i] == 0)
            for(int j = i; j <= 1000000; j += i) {
                primeFactors[j]++;
            }
    }

    int** fetchAns = new int*[10];
    for(int i = 0 ; i <= 10; i++) {
        fetchAns[i] = new int[1000000];
        for(int j = 0 ; j <= 1000000 ; j++) fetchAns[i][j] = 0;
    }


    for(int i = 1 ; i <= 10 ; i++) {
        for(int j = 1 ; j <= 1000000 ; j++) {
            fetchAns[i][j] = fetchAns[i][j-1];
            if(primeFactors[j] == i) fetchAns[i][j]++;
        }
    }

    for(int i = 0 ; i < t; i++) {
        // queries[i]
        if(queries[i].n == 0) {
            if(queries[i].a == 1) cout << 1 << endl;
            else {
                cout << 0 << endl;
            }
        }
        if(queries[i].a == 1) {
            cout << fetchAns[queries[i].n][queries[i].b] << endl;    
        }
        else {
            cout << fetchAns[queries[i].n][queries[i].b] - fetchAns[queries[i].n][queries[i].a] + 1 << endl; 
        }
    }
    return 0;
}