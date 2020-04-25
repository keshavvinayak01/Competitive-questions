    #include<bits/stdc++.h>
    typedef long long int lli;
    #define MOD 1000000007
    using namespace std;


    int main() {
        ios::sync_with_stdio(false);cin.tie(0);
        int t;
        cin >> t;
        while(t--) {
            int n, a, b, temp_b, max_char, j;
            bool change;
            char max_c;
            cin >> n >> a >> b;
            string s = "";
            for(int i = 0 ; i < n ; i += a) {
                max_char = 'a';
                j = a;
                temp_b = b;
                while(temp_b > 0) {
                    max_char = max_char == 'z' ? 'a' : char(max_char) + 1;
                    s += max_char;
                    temp_b--;
                    j--;
                }
                while(j > 0) {
                    s += max_char;
                    j--;
                }
            }
            s = s.substr(0, n);
            cout << s << endl;
        }
        return 0;
    }