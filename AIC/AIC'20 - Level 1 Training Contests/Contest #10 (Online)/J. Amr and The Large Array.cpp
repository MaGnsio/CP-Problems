//https://codeforces.com/group/aDFQm4ed6d/contest/279152/problem/J
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7, sz = 1000001;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n;
    cin >> n;
    ll a[n], f[sz] = {};
    pair<ll, ll> b[sz] = {{}};
    for (auto& x : a) cin >> x;
    for (auto& x : a) f[x]++;
    for (ll i = 0; i < n; ++i)
    {
        if (!b[a[i]].F) b[a[i]].F = i + 1;
        b[a[i]].S = i + 1;
    }
    ll mx = *max_element (f, f + sz), l = 0, r = LLONG_MAX;
    for (ll i = 0; i < sz; ++i)
    {
        if ((f[i] == mx) && (b[i].S - b[i].F + 1 <= r - l + 1)) l = b[i].F, r = b[i].S;
    }
    cout << l << " " << r;
}

