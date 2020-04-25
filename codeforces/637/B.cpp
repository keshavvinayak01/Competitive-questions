#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;
 
struct node {
    int l, r, peaks;
};
 
bool sortPeak(node x, node y) {
    if(x.peaks == y.peaks) return x.l < y.l;
    else return x.peaks > y.peaks;
}
 
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        lli arr[n];
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        int peaks[n];
        memset(peaks, 0, sizeof(peaks));
        for(int i = 1 ; i < n-1; i++) {
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) peaks[i] = 1;
        }
        vector<node> answers;
        node ans;
        ans.l = 0;
        ans.r = k-1;
        ans.peaks = 0;
        for(int i = 0 ; i < k ; i++) {
            if(peaks[i] == 1 && i != k-1 && i != 0) ans.peaks++;
        }
        if(ans.peaks > 0) 
            answers.push_back(ans);
        for(int i = 1 ; i <= n - k; i++) {
            ans.l = i;
            ans.r = i + k - 1;
            if(peaks[ans.l]) 
                ans.peaks--;
            if(peaks[ans.r - 1]) ans.peaks++;
            if(ans.peaks > 0) answers.push_back(ans);
        }
        sort(answers.begin(), answers.end(), sortPeak);
        if(answers.size() == 0) cout << "1 1" << endl;
        else cout << answers[0].peaks + 1 << " " << answers[0].l + 1 << endl;
    }
 
    return 0;
}