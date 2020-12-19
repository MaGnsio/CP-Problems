//https://codeforces.com/group/nVgev28wQI/contest/308101/problem/C
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, ans = 0;
    cin >> n;
    ll a[n], b[5] = {};
    for (auto& elem : a)
    {
        cin >> elem;
        if (elem < 10) b[0]++;
        else if (elem < 100) b[1]++;
        else if (elem < 1000) b[2]++;
        else if (elem < 10000) b[3]++;
        else if (elem < 100000) b[4]++;
    }
    for (ll i = 0; i < n; ++i)
    {
        ll p = 10;
        ans += (n - 1) * a[i];
        for (ll j = 0; j < 5; ++j)
        {
            if (a[i] < p && a[i] >= p / 10) ans += p * (b[j] - 1) * a[i];
            else ans += p * b[j] * a[i];
            p *= 10;
        }
    }
    cout << ans; 
}

