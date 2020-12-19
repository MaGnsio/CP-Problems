//https://codeforces.com/group/Rv2Qzg0DgK/contest/272489/problem/H
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
    vector<ll> v(n);
    for (auto& elem : v) cin >> elem;
    for (ll i = 1; i < n; ++i) v[i] += v[i - 1];
    for (ll i = 0; i < n - 1; ++i)
    {
        if (v[i] == v[n - 1] - v[i] ) ans++;
    }
    cout << ans;
}

