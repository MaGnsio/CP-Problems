//https://vjudge.net/contest/419723#problem/F
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

ll gcd (ll a, ll b)
{
    if (b == 0) return a;
    return gcd (b, a % b);
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, ans = 0;
    cin >> n;
    vector<ll> a(n), pre(n), suf(n);
    for (auto& x : a) cin >> x;
    pre[0] = a[0], suf[n - 1] = a[n - 1];
    for (ll i = 1; i < n; ++i) pre[i] = gcd (a[i], pre[i - 1]);
    for (ll i = n - 2; i >= 0; --i) suf[i] = gcd (a[i], suf[i + 1]);
    for (ll i = 0; i < n; ++i)
    {
        ll l = (i ? pre[i - 1] : 0);
        ll r = (i < n - 1 ? suf[i + 1] : 0);
        ll x = gcd (l, r);
        if (i == 0) ans = r;
        else if (i == n - 1) ans = ans * l / gcd (ans, l);
        else ans = ans * x / gcd (ans, x);
    }
    cout << ans;
}

