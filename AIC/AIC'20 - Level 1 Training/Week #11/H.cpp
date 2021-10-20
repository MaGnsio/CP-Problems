//https://codeforces.com/group/Rv2Qzg0DgK/contest/291373/problem/H
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
    ll n, k, ans = 0;
    cin >> n >> k;
    ll a[n], dp[n] = {};
    for (auto& elem : a) cin >> elem;
    dp[0] = a[0];
    for (ll i = 1; i < n; ++i) dp[i] = dp[i - 1] + a[i];
    for (ll i = 0; i < n; ++i)
    {
        ll l = i, r = n - 1;
        while (l <= r)
        {
            ll mid = l + (r - l) / 2;
            if (dp[mid] - (i ? dp[i - 1] : 0) <= k) l = mid + 1, ans = max (ans, mid - i + 1);
            else r = mid - 1;
        }
    }
    cout << ans;
}

