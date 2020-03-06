#include<bits/stdc++.h>
typedef long long int lli;
#define MOD 1000000007
using namespace std;

struct library {
    int n, s, time, num;
    int* books;
    library(int n_books, int s_i, int time_i, int* books_i) {
        n = n;
        books = books_i;
        s = s_i;
        time = time_i;
    }
};

bool comp_lib(library a, library b) {
    return a.time < b.time;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int b, l, ds;
    cin >> b >> l >> ds;
    int arr[b];
    int n, s, time;
    int* books;
    vector<library> libraries;
    for(int i = 0 ; i < b ; i++) cin >> arr[i];
    for(int i = 0 ; i < l ; i++) {
        cin >> n >> s >> time;
        books = new int[n];
        for(int i = 0 ; i < n ; i++) cin >> books[i];
        library x(n, s, time, books);
        x.num = i;
        libraries.push_back(x);
    }
    sort(libraries.begin(), libraries.end(), comp_lib);
    vector<library> ans;
    int i = 0;
    while(ds > 0) {
        ds -= libraries[i].time;
        if(ds > 0) {
            ans.push_back(libraries[i]);
            i++;
        }
        else break;
    }
    cout << i << endl;
    for(int i = 0 ; i < ans.size(); i++) {
        cout << libraries[i].num << " " << libraries[i].n << endl;
        for(int j = 0 ; j < libraries[i].n ; j++) cout << libraries[i].books[j] << " ";
        cout << "\n";
    }
    return 0;   
}