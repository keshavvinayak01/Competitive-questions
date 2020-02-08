#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n, m;
    cin >> n;
    int arr1[n];
    for(int i = 0 ; i < n ; i++) cin >> arr1[i];
    cin >> m;
    int arr2[m];
    for(int i = 0 ; i < m ; i++) cin >> arr2[i];
    vector<pair<int, int>> positions;
    for(int i = 0 ; i < n ; i++) {
        positions.push_back(make_pair(arr1[i], arr2[i]));
    }
    int ans = 0;
    // Solved in interviewBit; Just add the maximum of consecutive x or y distance.
    pair<int, int> curr_position = positions[0];
    for(int i = 1 ; i < positions.size(); i++) {
        ans += calc_distance(curr_position, positions[i]);
        curr_position = positions[i];
    }

    cout << ans << endl;
    return 0;
}