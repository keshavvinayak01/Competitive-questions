#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int m, c;

struct house {
    int x, y, power;
};

ll calc(house h) {
    return h.y - m*(h.x) - c;
}

ll getMaxPower(house* houses, int n) {
    ll side1 = 0;
    ll side2 = 0;
    for(int i = 0 ; i < n ; i++) {
        if(calc(houses[i]) > 0) side1 += houses[i].power;
        else                    side2 += houses[i].power;
    }
    return max(side1, side2);
}


int main() {
    int n;
    cin >> n;
    cin >> m >> c;
    house* houses = new house[n];
    for(int i = 0 ; i < n ; i++) {
        cin >> houses[i].x >> houses[i].y >> houses[i].power;
    }
    cout << getMaxPower(houses, n) << endl;
    return 0;
}