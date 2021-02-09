//https://codeforces.com/group/Rv2Qzg0DgK/contest/292431/problem/M
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

void solve ()
{
    ll n, ans = 0;
    cin >> n;
    ll a[n], v[n + 1] = {};
    for (auto& elem : a) cin >> elem, v[elem]++;
    for (ll i = 0; i < n; ++i)
    {
        ll x = a[i];
        for (ll j = i + 1; j < n; ++j)
        {
            x += a[j];
            if (x > n) break;
            if (v[x]) ans += v[x], v[x] = 0;
        }
    }
    cout << ans << "\n";
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--) solve ();
}

