#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.second != b.second){
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main(){

    int n, k;
    cin >> n >> k;
    pair<int, int>* pieces = new pair<int, int>[n];
    for(int i=0; i< n; i++)
        cin >> pieces[i].first >> pieces[i].second;

    sort(pieces, pieces + n, cmp);
    multiset<int> m;
    int weight;
    for(int i=0; i< k;i++){
        cin >> weight;
        m.insert(weight);
    }
    long ans = 0;
    for(int i=0; i < n;i++){
        if(m.empty()) break;
        else if(m.lower_bound(pieces[i].first) != m.end()){
            ans += pieces[i].second;
            m.erase(m.lower_bound(pieces[i].first));
        }
    }
    return 0;
}