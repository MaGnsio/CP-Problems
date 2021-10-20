//https://vjudge.net/contest/416230#problem/N
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
    ll p = 1;
    ll dp[33] = {};
    for (auto& elem : dp) elem = p, p *= 2;
    ll n, m;
    cin >> n >> m;
    ll a[n][m];
    for (auto& rows : a) for (auto& elem : rows) cin >> elem;
    for (ll i = 0; i < n; ++i)
    {
        if (a[i][0] == 1) continue;
        for (ll j = 0; j < m; ++j) a[i][j] = (a[i][j] ? 0 : 1);
    }
    ll pow = m - 1, ans = 0;
    for (ll i = 0; i < m; ++i)
    {
        ll cnt1 = 0, cnt2 = 0;
        for (ll j = 0; j < n; ++j)
        {
            if (a[j][i]) cnt1++;
            else cnt2++;
        }
        ans += max (cnt1, cnt2) * dp[pow--];
    }
    cout << ans;
}
