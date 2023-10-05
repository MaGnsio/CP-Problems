//https://codeforces.com/contest/1492/problem/C
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
    ll n, m, mx = 1;
    string s, t;
    cin >> n >> m >> s >> t;
    ll pre[m], suf[m];
    for (ll i = 0, j = 0; i < n && j < m; ++i) if (s[i] == t[j]) pre[j++] = i;
    for (ll i = n - 1, j = m - 1; i >= 0 && j >= 0; --i) if (s[i] == t[j]) suf[j--] = i;
    for (ll i = 0; i < m - 1; ++i) mx = max (mx, suf[i + 1] - pre[i]);
    cout << mx;
}

