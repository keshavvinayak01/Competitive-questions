#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

int getAns(vector<int> people) {
    int temp_ans = 0;
    int mul = 4;
    sort(people.begin(), people.end());
    for(int i = people.size() - 1 ; i >= 0; i--) {
        if(people[i] == 0) temp_ans -= 100;
        else {
            temp_ans += mul*25*people[i];
            mul--;
        }
    }
    return temp_ans;
}


int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t, ans = 0, time;
    vector<int> answers;
    char show;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int temp_ans = INT_MIN;
        int show_people[4][4];
        for(int i = 0 ; i < 4 ; i++) {
            for(int j = 0 ; j < 4 ; j++) show_people[i][j] = 0;
        }
        while(n--) {
            cin >> show >> time;
            show_people[show - 'A'][time/3-1]++;
        }
        vector<int> people;
        // 
        for(int i = 0 ; i < 4 ; i++) 
            for(int j = 0 ; j < 4 ; j++) 
                if(j != i)
                    for(int k = 0 ; k < 4 ; k++ ) 
                        if(k != i && k != j)
                        for(int l = 0 ; l < 4 ; l++) 
                            if(l != i && l != j && l != k) {
                                people.clear();
                                people.push_back(show_people[0][i]);
                                people.push_back(show_people[1][j]);
                                people.push_back(show_people[2][k]);
                                people.push_back(show_people[3][l]);
                                temp_ans = max(temp_ans, getAns(people));
                            }
        answers.push_back(temp_ans);
        ans += temp_ans;
    }
    answers.push_back(ans);
    for(int i = 0 ; i < answers.size() ; i++) {
        cout << answers[i] << endl;
    }
    return 0;
}