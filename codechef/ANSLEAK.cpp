#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

struct answer {
    int ans;
    float freq;
};

bool reverseSort(answer a, answer b) {return a.freq > b.freq;}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int n, m, k;
    int t, prob1, prob2, r;
    answer temp_ans;
    cin >>t;
    while(t--) {
        cin >> n >> m >> k;
        int answers[n][k];
        for(int i = 0 ; i < n ; i++) 
            for(int j = 0 ; j < k ; j++) 
                cin >> answers[i][j];
        for(int i = 0 ; i < n ; i++) {
            map<int, int> freq;
            for(int j = 0 ; j < k ; j++) {
                freq[answers[i][j]]++;
            }
            vector<answer> ans_freq;
            for(int j = 1 ; j <= m ; j++) {
                temp_ans.ans = j;
                temp_ans.freq = freq[j];
                ans_freq.push_back(temp_ans);
            }
            // cout << "*********\n";
            // for(int i = 0 ; i < ans_freq.size(); i++) {
            //     cout << ans_freq[i].ans << " " << ans_freq[i].freq << endl;
            // }
            // cout << "*********\n";
            sort(ans_freq.begin(), ans_freq.end(), reverseSort);
            prob1 = (ans_freq[0].freq / (ans_freq[0].freq + ans_freq[1].freq))*100;
            prob2 = 100 - prob1;
            r = rand()%100;        
            if (r <= prob2) cout << ans_freq[1].ans << " "; 
            else            cout << ans_freq[0].ans << " ";
        }
        cout << endl;
    }
    return 0;
}