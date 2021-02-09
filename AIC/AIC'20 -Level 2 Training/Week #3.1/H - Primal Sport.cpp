//https://vjudge.net/contest/419722#problem/H
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
    ll n;
    cin >> n;
    ll a[n + 1] {};
    for (ll i = 2; i <= n; ++i)
    {
        if (!a[i])
        {
            for (ll j = 2 * i; j <= n; j += i) a[j] = i;
        }
        a[i] = i - a[i] + 1;
    }
    ll ans = n;
    for (ll i = a[n]; i <= n; ++i) ans = min (ans, a[i]);
    cout << ans;
}
