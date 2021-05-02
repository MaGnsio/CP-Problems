//https://atcoder.jp/contests/abc185/tasks/abc185_b
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
    ll n, m, t;
    cin >> n >> m >> t;
    vector<pair<ll, ll>> a(m);
    for (auto& x : a) cin >> x.F >> x.S;
    ll curn = n, d = 0;
    for (ll i = 0; i < m; ++i)
    {
        if (curn - a[i].F + d <= 0) return cout << "No", 0;
        curn = min (n, max (curn - a[i].F + d, 0ll) + (a[i].S - a[i].F));
        d = a[i].S;
    }
    cout << (t - d >= curn ? "No" : "Yes");
}

