//https://atcoder.jp/contests/abc186/tasks/abc186_d
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
    ll n, sum = 0;
    cin >> n;
    ll a[n], dp[n] = {};
    for (auto& x : a) cin >> x;
    sort (a, a + n, greater<ll> ());
    dp[0] = a[0];
    for (ll i = 1; i < n; ++i) dp[i] = a[i] + dp[i - 1];
    for (ll i = 0; i < n; ++i)
    {
        sum += abs ((n - i - 1) * (a[i]) - (dp[n - 1] - dp[i]));
    }
    cout << sum;
}

