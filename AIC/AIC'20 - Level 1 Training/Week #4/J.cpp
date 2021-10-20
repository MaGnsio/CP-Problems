//https://codeforces.com/group/Rv2Qzg0DgK/contest/273155/problem/J
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
    ll n, q, l, r, sum = 0;
    cin >> n >> q;
    ll a[n], dp[n + 2] = {};
    for (auto& elem : a) cin >> elem;
    while (q--)
    {
        cin >> l >> r;
        dp[l]++, dp[r + 1]--;
    }
    for (ll i = 1; i < n + 1; ++i) dp[i] += dp[i - 1];
    sort (a, a + n, greater<ll> ());
    sort (dp, dp + n + 2, greater<ll> ());
    for (ll i = 0; i < n; ++i) sum += (a[i] * dp[i]);
    cout << sum;
}

