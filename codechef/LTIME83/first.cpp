#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

bool sortThis(pair<int, int> a, pair<int, int> b) {return a.first < b.first;}

float triangle_area(float x1, float y1, float x2, float y2, float x3, float y3){
    return abs(0.5*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)));
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t, a, b;
    float area, area1, area2, area3;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        vector<pair<int, int>> points, queries;
        vector<int> px(n), py(n);
        for(int i = 0 ; i < n ; i++) {
            cin >> a >> b;
            points.push_back(make_pair(a, b));
        }
        sort(points.begin(), points.end(), sortThis);
        for(int i = 0 ; i < n ; i++){px[i] = points[i].first; py[i] = points[i].second;}

        for(int i = 0 ; i < q ; i++) {
            cin >> a >> b;
            queries.push_back(make_pair(a, b));
        }
        int ans[q];
        memset(ans, 0, sizeof(ans));
        int start, end;
        for(int i = 0 ; i < q ; i++) {
            area = 0.25 * (queries[i].second - queries[i].first) * (queries[i].second - queries[i].first);
            start = lower_bound(px.begin(), px.end(), queries[i].first) - px.begin();
            end = upper_bound(px.begin(), px.end(), queries[i].second) - px.begin();
            for(int j = start; j < end && j < n ; j++) {
                area1 = triangle_area(queries[i].first, 0, queries[i].second, 0, px[j], py[j]);
                area2 = triangle_area(0.5*(queries[i].first + queries[i].second), 
                                        0.5*(queries[i].second - queries[i].first),
                                        px[j], py[j],queries[i].first, 0);
                area3 = triangle_area(0.5*(queries[i].first + queries[i].second), 
                                            0.5*(queries[i].second - queries[i].first),
                                            px[j], py[j],queries[i].second, 0);
                if(area1 + area2 + area3 == area) ans[i]++;
            }
        }
        for(int i = 0 ; i < q ; i++) cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}