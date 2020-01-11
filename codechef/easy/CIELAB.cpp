    #include<bits/stdc++.h>
    using namespace std;

    int main() {
        int a, b;
        cin >> a >> b;
        int mainAns = a - b;
        if(mainAns % 10 != 9) cout << mainAns+1 << endl;
        else cout << mainAns - 1 << endl;
        return 0;
    }