//https://codeforces.com/contest/1491/problem/B
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void solve ()
{
    ll n, u, v, ans = LLONG_MAX;
    cin >> n >> u >> v;
    ll a[n];
    for (auto& x : a) cin >> x;
    for (ll i = 1; i < n; ++i)
    {
        if (abs (a[i] - a[i - 1]) > 1) ans = 0;
        if (abs (a[i] - a[i - 1]) == 1) ans = min ({ans, u, v});
        if (a[i] == a[i - 1]) ans = min (ans, v + min (u, v));
    }
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

