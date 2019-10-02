#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> price_rating;
    int price_temp, rating_temp;
    for(int i = 0 ; i < n; i++){
        cin >> price_temp >> rating_temp;
        price_rating.push_back(make_pair(price_temp, rating_temp));
    }
    int q;
    cin >> q;
    vector<pair<int, int>> range;
    int range_temp[2];
    for(int i = 0; i < q; i++){
        cin >>range_temp[0] >> range_temp[1];
        range.push_back(make_pair(range_temp[0], range_temp[1]));
    }
    sort(price_rating.begin(), price_rating.end(), compare);
    for(int i = 1; i < n; i++){
        if(price_rating[i].second < price_rating[i-1].second){
            price_rating[i].second = price_rating[i-1].second;
        }
    }
    vector<int> price(n);
    vector<int> rating(n);
    for(int i = 0 ; i< n; i++){
        price[i] = price_rating[i].first;
        rating[i] = price_rating[i].second;
    }
    int ans;
    for(int i = 0 ; i < q; i++){
        if(range[i].first > price[n-1]){
            cout << "-1" << endl;
        }
        else if(range[i].second < price[0]){
            cout << "-1" << endl;
        }
        else{
            ans = upper_bound(price.begin(), price.end(), range[i].second) - price.begin();
            cout << rating[ans - 1] << endl;
        }
         
    }
    return 0;
}