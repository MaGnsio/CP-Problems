//https://vjudge.net/contest/416254#problem/H
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

void solve (ll i)
{
    ll n, xl, yl, xr, yr;
    cin >> n >> xl >> yl >> xr >> yr;
    for (ll j = 1; j < n; ++j)
    {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        xl = max (xl, x1);
        yl = max (yl, y1);
        xr = min (xr, x2);
        yr = min (yr, y2);
    }
    ll w = max (0ll, xr - xl), l = max (0ll, yr - yl);
    cout << "Case #" << i << ": " << w * l << "\n";
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t, i = 0;
    cin >> t;
    while (t--) solve (++i);
}

