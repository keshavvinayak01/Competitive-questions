#include<bits/stdc++.h>
using namespace std;

struct Worker{
    int time;
    float rate;
};


bool CompareThis(Worker a, Worker b){
    return a.time < b.time;
}


int main(int argc, char const *argv[]) {
    int n;
    long long d;
    vector<Worker> a;
    cin >> n >> d;
    int temp = n;
    while(n--){
        int t;
        float x,y;
        cin >> t >> x >> y;
        a.push_back({t, y/x});
    }
    sort(a.begin(), a.end(), CompareThis);
    int price = 0;
    int i = 0;
    while(d > 0 && i < temp){
        // cout << price <<" " << d <<" " <<  i << endl;
        if(a[i].rate <= a[i+1].rate && a[i].time == a[i+1].time){
            i++;
        }
        else{
            int temp_i = i+1;
            while(a[temp_i].rate <= a[i].rate && temp_i < temp){
                temp_i++;
            }
            if(temp_i >= temp){
                price += ceil(d/a[i].rate);
                d = 0;
                break;
            }
            price += (a[temp_i].time - a[i].time);
            d = d - a[i].rate*(a[temp_i].time - a[i].time);
            i = temp_i;
        }
    }
    cout << price << endl;
    return 0;
}