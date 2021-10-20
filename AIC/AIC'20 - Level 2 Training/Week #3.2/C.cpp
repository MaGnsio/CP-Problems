//https://vjudge.net/contest/419723#problem/C
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

void solve (ll n, ll d)
{
    ll f = 1;
    map<ll, ll> a, b;
    for (ll i = n; i > 1; --i)
    {
        ll cpy = i;
        for (ll j = 2; j * j <= cpy; ++j)
        {
            while (cpy % j == 0) cpy /= j, a[j]++;
        }
        if (cpy > 1) a[cpy]++;
    }
    for (ll i = 2; i * i <= d; ++i)
    {
        while (d % i == 0) d /= i, b[i]++;
    }
    if (d != 1) b[d]++;
    for (auto& x : a)
    {
        ll y = x.S - b[x.F];
        b[x.F] = 0;
        if (y < 0)
        {
            cout << 0 << "\n";
            return;
        }
        f *= (y + 1);
    }
    for (auto& x : b)
    {
        if (x.S > 0)
        {
            cout << 0 << "\n";
            return;
        }
    }
    cout << f << "\n";
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, d;
    while (cin >> n >> d && (n || d)) solve (n, d);
}

