//https://atcoder.jp/contests/abc188/tasks/abc188_d
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
    ll n, c, ans = 0;
    cin >> n >> c;
    vector<pair<ll, ll>> v;
    for (ll i = 0; i < n; ++i)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        v.push_back ({a - 1, c});
        v.push_back ({b, -c});
    }
    sort (v.begin (), v.end ());
    ll t = 0, p = 0;
    for (auto& x : v)
    {
        if (x.F != t)
        {
            ans += min (c, p) * (x.F - t);
            t = x.F;
        }
        p += x.S;
    }
    cout << ans;
}

