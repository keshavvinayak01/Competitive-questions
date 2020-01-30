/*
    Vova again tries to play some computer card game.
    The rules of deck creation in this game are simple. Vova is given an existing deck of n cards 
    and a magic number k. The order of the cards in the deck is fixed. Each card has a number 
    written on it; number ai is written on the i-th card in the deck.

    After receiving the deck and the magic number, Vova removes x (possibly x = 0) cards from the 
    top of the deck, y (possibly y = 0) cards from the bottom of the deck, and the rest of the deck 
    is his new deck (Vova has to leave at least one card in the deck after removing cards). So 

    Vova's new deck actually contains cards x + 1, x + 2, ... n - y - 1, n - y from the original deck.

    Vova's new deck is considered valid iff the product of all numbers written on the cards in his 
    new deck is divisible by k. So Vova received a deck (possibly not a valid one) and a number k, 
    and now he wonders, how many ways are there to choose x and y so the deck he will get after 
    removing x cards from the top and y cards from the bottom is valid?

*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool compareVectorPair(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

vector<pair<int, int>> combineFactors(vector<pair<int, int>> x, vector<pair<int, int>> y) {
    cout << "Started combineFactors\n";
    vector<pair<int, int>> ans = x;
    int x_size = x.size();
    int y_size = y.size();
    cout << "Nani desune " << x_size << " " << y_size << endl;
    int max_factor = max(x[x_size - 1].first, y[y_size - 1].first);
    cout << "What error? " << max_factor << endl;
    int* factor_map = new int[max_factor + 1];
    // int factor_map[max_factor + 1];
    for(int i = 0 ; i <= max_factor; i++) factor_map[i] = 0;
    
    for(int i = 0 ; i < x_size; i++) {
        factor_map[x[i].first] += x[i].second;
    }

    for(int i = 0 ; i < y_size; i++) {
        factor_map[y[i].first] += y[i].second;
    }

    for(int i = 2 ; i <= max_factor; i++) {
        if(factor_map[i] > 0)
            ans.push_back(make_pair(i, factor_map[i]));
    }
    cout << "Ended combineFactors\n";
    delete[] factor_map;
    return ans;
}

bool factorsMatch(vector<pair<int, int>> a, vector<pair<int, int>> b) {
    int maxFactor = max(a[a.size() - 1].first, b[b.size() - 1].first);

    int* factor_map_a = new int[maxFactor + 1];
    int* factor_map_b = new int[maxFactor + 1];
    
    int a_size = a.size();
    int b_size = b.size();

    for(int i = 0 ; i < a_size; i++) {
        factor_map_a[a[i].first] += a[i].second;
    }

    for(int i = 0 ; i < b_size; i++) {
        factor_map_b[b[i].first] += b[i].second;
    }

    for(int i = 2 ; i <= maxFactor; i++) {
        if(factor_map_b[i] > 0 && factor_map_a[i] < factor_map_b[i]) {
            delete[] factor_map_a;
            delete[] factor_map_b;
            return false;
        }
    }
    delete[] factor_map_a;
    delete[] factor_map_b;
    return true;
}

vector<pair<int, int>> getPrimeFactors(ll k) {
    
    ll temp = k;
    vector<pair<int, int>> factors;
    for(int i = 2; i*i <=temp ; i++) {
        int power = 0;
        while(k%i == 0) {
            k /= i;
            power++;
        }
        if(power > 0)
            factors.push_back(make_pair(i, power));
    }
    if (factors.size() == 0) {
        factors.push_back(make_pair(k, 1));
    }
    return factors;
}

int main() {
    int n, k;
    cin >> n >> k;
    int* arr = new int[n];
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    
    vector<pair<int, int>> kFactors = getPrimeFactors(k);
    int i = 1;
    vector<pair<int, int>> currFactors;
    int ans = 0;

    for(int j = 0 ; j < n ; j++) {
        cout << "j : " <<  j << endl;
        vector<pair<int, int>> jFactors = getPrimeFactors(arr[j]);
        i = max(j+1, i);
        while(i < n) {
            cout <<"i : " <<  i << endl;
            currFactors = getPrimeFactors(arr[i]); 
            currFactors = combineFactors(jFactors, currFactors);
            cout <<"i : " <<  i << endl;
            if(factorsMatch(currFactors, kFactors)) {
                // Remove jFactors
                int jsize = jFactors[jFactors.size()-1].first + 1;
                int* jFactorMap = new int[jsize + 1];
                for(int k = 2; k <= jsize; k++) jFactorMap[k] = 0;
                for(int k = 0 ; k <= jFactors.size(); k++) {
                    jFactorMap[jFactors[k].first] += jFactors[k].second;
                }

                for(int k = 0 ; k < currFactors.size(); k++) {
                    if(jFactorMap[currFactors[k].first] > 0) {
                        currFactors[k].second -= jFactorMap[currFactors[k].first];
                    }
                }
                delete[] jFactorMap;
                break;
            }
            i++;
        }
        // add n-i to the sum;
        ans += n - i;

    }
    cout << ans << endl;
    return 0;
}