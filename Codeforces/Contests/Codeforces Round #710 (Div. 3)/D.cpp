//https://codeforces.com/contest/1506/problem/D
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void solve ()
{
    ll n;
    cin >> n;
    map<ll, ll> m;
    for (ll i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        m[x]++;
    }
    ll sum = 0, ma = LLONG_MIN, ans = 0;
    for (auto& x : m)
    {
        sum += x.S;
        ma = max (ma, x.S);
    }
    if (n & 1) ans = 1;
    ans = max (ans, 2 * ma - sum);
    cout << ans << "\n";
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--)
        solve ();
}

