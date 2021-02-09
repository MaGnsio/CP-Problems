//https://vjudge.net/contest/416254#problem/U
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
    ll n, sum = 0, pt = 1;
    cin >> n;
    ll a[n];
    for (auto& elem : a) cin >> elem;
    for (ll i = 0; i < 60; ++i)
    {
        ll ctr_0 = 0, ctr_1 = 0;
        for (ll j = 0; j < n; ++j) ctr_0 += !(a[j] & 1), ctr_1 += (a[j] & 1), a[j] >>= 1LL;
        sum += (((ctr_0 * ctr_1) % mod) * pt) % mod;
        sum %= mod, pt *= 2, pt %= mod;
    }
    cout << sum;
}

