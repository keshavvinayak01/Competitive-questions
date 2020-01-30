#include<bits/stdc++.h>
using namespace std;

struct Triangle{
    int a, b, c;
};

bool isTriangle(Triangle t){
    if(t.a + t.b > t.c && t.a + t.c > t.b && t.c + t.b > t.a){
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(a, a+n);
    cout << endl;
    Triangle ans = {a[n-1], -1, -1};
    for(int i=n-2; i >=0; i--){
        for(int j=i-1; j >=0; j--){
            // cout << a[n-1] << " " << a[i] << " " << a[j] << " was considered" << endl;
            Triangle temp = {a[n-1], a[i], a[j]};
            if(isTriangle(temp)){
                ans = temp;
                break;
            }
        }
        if(ans.b != -1) break;
    }
    int nums[] = {ans.a, ans.b, ans.c};
    if(isTriangle(ans)){
        sort(nums, nums+3);
        cout << nums[0] << " " << nums[1] << " " << nums[2] << endl;
    }
    else{
        cout << "-1" << endl;
    }
    return 0;
}
