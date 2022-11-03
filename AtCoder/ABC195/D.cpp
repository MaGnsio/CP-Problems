//https://atcoder.jp/contests/abc195/tasks/abc195_d
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
    ll n, m, q;
    cin >> n >> m >> q;
    pair<ll, ll> a[n], b[m];
    for (auto& x : a) cin >> x.S >> x.F;
    for (ll i = 0; i < m; ++i)
    {
        cin >> b[i].F;
        b[i].S = i + 1;
    }
    sort (a, a + n, greater<pair<ll, ll>> ());
    sort (b, b + m);
    while (q--)
    {
        ll l, r, v = 0;
        cin >> l >> r;
        unordered_set<ll> s;
        for (ll i = 0; i < n; ++i)
        {
            for (ll j = 0; j < m; ++j)
            {
                if (s.count (b[j].S) || (b[j].S >= l && b[j].S <= r)) continue;
                if (b[j].F >= a[i].S)
                {
                    v += a[i].F;
                    s.insert (b[j].S);
                    break;
                }
            }
        }
        cout << v << "\n";
    }
}

