//https://vjudge.net/contest/419723#problem/P
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

ll modpow (ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b % 2 == 1) res = ((res % mod) * (a % mod)) % mod;
        a = ((a % mod) * (a % mod)) % mod;
        b /= 2;
    }
    return res;
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, k, ans = 0;
    cin >> n >> k;
    vector<ll> dp(k + 1, 0);
    for (ll i = k; i >= 1; --i)
    {
        ll cnt = k / i;
        ll p = modpow (cnt, n);
        for (ll j = 2; i * j <= k; ++j)
        {
            p -= dp[i * j];
            if (p < 0) p += mod;
            p %= mod;
        }
        dp[i] = p;
        ans += (p * i) % mod;
    }
    cout << ans % mod;
}

