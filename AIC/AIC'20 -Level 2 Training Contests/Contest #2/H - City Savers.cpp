//https://vjudge.net/contest/415649#problem/H
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);\
    ll n, ans = 0;
    cin >> n;
    ll a[n + 1], b[n];
    for (auto& elem : a) cin >> elem;
    for (auto& elem : b) cin >> elem;
    for (ll i = 0; i < n; ++i)
    {
        ans += min (a[i], b[i]);
        b[i] = max (0ll, b[i] - a[i]);
        ans += min (a[i + 1], b[i]);
        a[i + 1] -= min (a[i + 1], b[i]);
    }
    cout << ans;
}

