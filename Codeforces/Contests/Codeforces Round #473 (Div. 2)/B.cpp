//https://codeforces.com/contest/959/problem/B
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, k, m, ans = 0;
    cin >> n >> k >> m;
    ll a[n];
    string c[n];
    for (auto& x : c) cin >> x;
    for (auto& x : a) cin >> x;
    unordered_map<string, ll> v;
    for (ll i = 0; i < n; ++i) v[c[i]] = a[i];
    for (ll i = 0; i < k; ++i)
    {
        ll x, idx;
        cin >> x;
        ll t[x];
        for (auto& y : t) cin >> y;
        idx = t[0] - 1;
        for (auto& y : t) if (v[c[y - 1]] < v[c[idx]]) idx = y - 1;
        for (auto& y : t) v[c[y - 1]] = min (v[c[y - 1]], a[idx]);
    }
    for (ll i = 0; i < m; ++i)
    {
        string x;
        cin >> x;
        ans += v[x];
    }
    cout << ans;
}

