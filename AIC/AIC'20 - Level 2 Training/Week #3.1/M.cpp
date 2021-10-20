//https://vjudge.net/contest/419722#problem/M
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
const ll sz = 10'000'001;

vector<bool> ip(sz, true);
vector<ll> f(sz, 0), dp(sz, 0), p;
void init ()
{
    ip[0] = ip[1] = false;
    for (ll i = 2; i < sz; ++i)
    {
        if (ip[i])
        {
            p.push_back (i);
            for (ll j = 2 * i; j < sz; j += i) ip[j] = false;
        }
    }
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    init ();
    ll n, q;
    cin >> n;
    for (ll i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        f[x]++;
    }
    for (ll i = 0; i < p.size (); ++i)
    {
        for (ll j = p[i]; j < sz; j += p[i]) dp[p[i]] += f[j];
    }
    for (ll i = 1; i < sz; ++i) dp[i] += dp[i - 1];
    cin >> q;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        l = min (l , sz), r = min (r, sz - 1);
        cout << dp[r] - dp[l - 1] << "\n";
    }
}

