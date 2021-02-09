//https://codeforces.com/group/Rv2Qzg0DgK/contest/292431/problem/O
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
    ll n, d;
    cin >> n >> d;
    ll dp[n];
    pair<ll, ll> a[n];
    for (auto& elem : a) cin >> elem.F >> elem.S;
    sort (a, a + n);
    dp[0] = a[0].S;
    for (ll i = 1; i < n; ++i) dp[i] = a[i].S + dp[i - 1];
    ll l = 0, r = 0, ans = 0;
    while (r < n)
    {
        while (a[r].F - a[l].F < d && r < n) ans = max (ans, dp[r++] - (l ? dp[l - 1] : 0));
        if (a[r].F - a[l].F >= d && l <= r) l++;
    }
    cout << ans;
}

