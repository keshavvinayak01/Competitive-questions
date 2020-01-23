#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;

struct person{
    lli arrival, departure, comp;
};

lli getMaxSchedule(vector<person>& customers) {
    lli ans = 1;
    lli y = 0;
    for(lli i = 1 ; i < customers.size(); i++) {
        if(customers[i].arrival >= customers[y].departure) {
            ans++;
            y = i;
        }
    }
    return ans;
}

bool withinSegComp(person a, person b) {
    return a.departure < b.departure;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    lli t, n, k, a, b, c, ans;
    cin >> t;
    while(t--) {
        ans = 0;
        cin >> n >> k;
        map<lli, vector<person>> customers;
        map<lli, vector<person>>::iterator it;
        person temp;
        for(lli i = 0 ; i < n ; i++) {
            cin >> a >> b >> c;
            temp.arrival = a;
            temp.departure = b;
            temp.comp = c;
            customers[c].push_back(temp);
        }
        for(it = customers.begin(); it != customers.end(); it++) {
            vector<person> customer_segment = it->second;
            sort(customer_segment.begin(), customer_segment.end(), withinSegComp);
            ans = ans + getMaxSchedule(customer_segment);
        }
        cout << ans << endl;
        
    }

    return 0;
}