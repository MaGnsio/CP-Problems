//https://vjudge.net/contest/417537#problem/C
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
    ll n, m;
    cin >> n >> m;
    ll a[n] = {};
    set<ll> s;
    for (ll i = 0; i <= n; ++i) s.insert (i);
    while (m--)
    {
        ll l, r, x;
        vector<ll> d;
        cin >> l >> r >> x;
        l--, r--, x--;
        auto it = s.lower_bound (l);
        while (it != s.end ())
        {
            ll cur = *it;
            if (cur > r) break;
            if (cur != x) d.push_back (cur), a[cur] = x + 1;
            it++;
        }
        for (ll i = 0; i < d.size (); ++i) s.erase (d[i]);
    }
    for (auto& elem : a) cout << elem << " ";
}

