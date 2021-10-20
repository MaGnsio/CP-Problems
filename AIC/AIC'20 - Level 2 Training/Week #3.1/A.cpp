//https://vjudge.net/contest/419722#problem/A
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1073741824;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll a, b, c, n, sum = 0;
    cin >> a >> b >> c;
    n = a * b * c;
    vector<ll> d(n + 1);
    for (ll i = 1; i <= n; ++i)
    {
        for (ll j = i; j <= n; j += i) d[j]++;
    }
    for (ll i = 1; i <= a; ++i)
    {
        for (ll j = 1; j <= b; ++j)
        {
            for (ll k = 1; k <= c; ++k)
            {
                sum = ((sum % mod) + (d[i * j * k] % mod)) % mod;
            }
        }
    }
    cout << (sum % mod);
}

