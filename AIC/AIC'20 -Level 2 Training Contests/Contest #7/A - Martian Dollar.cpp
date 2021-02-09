//https://vjudge.net/contest/421809#problem/A
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
    ll a[n];
    for (auto& x : a) cin >> x;
    ll ans = m;
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = i + 1; j < n; ++j)
        {
            ll x = m - (m / a[i]) * a[i] + (m / a[i]) * a[j];
            ans = max (ans, x);
        }
    }
    cout << ans;
}

