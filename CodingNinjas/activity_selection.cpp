#include<bits/stdc++.h>
using namespace std;

bool compareSecond(pair<int, int> a1, pair<int, int> a2){
    return a1.second < a2.second;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector< pair<int, int> > a;
    for(int i=0; i < n; i++){
        int b, c;
        cin >> b >> c;
        a.push_back(make_pair(b,c));
    }
    sort(a.begin(), a.end(), compareSecond);
    int max_now = a[0].second;
    int count = 1;
    for(int i=1; i < n; i++){
        if(a[i].first >= max_now){
            count++;
            max_now = a[i].second;
        }
    }

    cout << count << endl;
    return 0;
}
