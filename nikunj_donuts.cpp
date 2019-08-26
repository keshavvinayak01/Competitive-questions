#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);

    long long result = 0;
    for (long long i = n-1; i >= 0; i--)
    {
        /* code */
        result += a[i]*pow(2, n - i - 1);
    }
    
    cout << result << endl;
    return 0;
}
