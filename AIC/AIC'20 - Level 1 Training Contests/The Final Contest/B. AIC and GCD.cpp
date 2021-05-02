//https://codeforces.com/group/aDFQm4ed6d/contest/298276/problem/B
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

ll gcd (ll a, ll b) {return (b ? gcd (b, a % b) : a);}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n;
    cin >> n;
    ll a[n], pre[n], suf[n];
    for (auto& x : a) cin >> x;
    pre[0] = a[0], suf[n - 1] = a[n - 1];
    for (ll i = 1; i < n; ++i) pre[i] = gcd (pre[i - 1], a[i]);
    for (ll i = n - 2; i >= 0; --i) suf[i] = gcd (suf[i + 1], a[i]);
    ll ans = suf[0];
    for (ll i = 0; i < n; ++i)
    {
        ans = max (ans, gcd ((i ? pre[i - 1] : 0), (i + 1 < n ? suf[i + 1] : 0)));
    }
    cout << ans;
}

