//https://vjudge.net/contest/416541#problem/B
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

ll bs (vector<pair<ll, ll>> &v, ll f)
{
    ll l = 0, r = v.size () - 1, ans = 0;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (v[mid].F <= f) l = mid + 1, ans = v[mid].S;
        else r = mid - 1;
    }
    return ans;
}
void solve ()
{
    ll n, q;
    cin >> n >> q;
    map<ll, ll> a;
    for (ll i = 0; i < n; ++i)
    {
        ll d, h, m, r;
        cin >> d >> h >> m >> r;
        ll start = (d * 60 * 60) + (h * 60) + m;
        ll end = start + (r * 60 * 60);
        a[start]++, a[end]--;
    }
    vector<pair<ll, ll>> dp;
    for (auto& x : a) dp.push_back (make_pair (x.F, x.S));
    for (ll i = 1; i < dp.size (); ++i) dp[i].S += dp[i - 1].S;
    while (q--)
    {
        ll d, h, m;
        cin >> d >> h >> m;
        ll f = (d * 60 * 60) + (h * 60) + m;
        cout << bs (dp, f) << "\n";
    }
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--) solve ();
}

