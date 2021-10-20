//https://codeforces.com/group/aDFQm4ed6d/contest/287686/problem/J
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
    ll n, m, k, d = 0;
    cin >> n >> m >> k;
    ll a[n + 2] = {}, b[m + 2][4] = {}, f[n + 2] = {};
    for (ll i = 1; i <= n; ++i) cin >> a[i];
    for (ll i = 1; i <= m; ++i) cin >> b[i][0] >> b[i][1] >> b[i][2];
    for (ll i = 1; i <= k; ++i)
    {
        ll x, y;
        cin >> x >> y;
        b[x][3]++, b[y + 1][3]--;
    }
    for (ll i = 1; i <= m; ++i) b[i][3] += b[i - 1][3];
    for (ll i = 1; i <= m; ++i) f[b[i][0]] += (b[i][2] * b[i][3]), f[b[i][1] + 1] -= (b[i][2] * b[i][3]);
    for (ll i = 1; i <= n; ++i) f[i] += f[i - 1];
    for (ll i = 1; i <= n; ++i) cout << a[i] + f[i] << " ";
}

