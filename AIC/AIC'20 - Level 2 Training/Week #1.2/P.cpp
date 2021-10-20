//https://vjudge.net/contest/416254#problem/P
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

bool is_friend (ll x, ll y, ll k, ll n)
{
    ll ctr = 0;
    for (ll i = 0; i < n; ++i, x >>= 1, y >>= 1) ctr += ((x & 1) ^ (y & 1));
    return ctr <= k;
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, m, k, cnt = 0;
    cin >> n >> m >> k;
    ll a[m + 1];
    for (auto& elem : a) cin >> elem;
    for (ll i = 0; i < m; ++i) cnt += is_friend (a[i], a[m], k, n);
    cout << cnt;
}
