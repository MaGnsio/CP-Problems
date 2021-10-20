//https://vjudge.net/contest/419722#problem/C
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

ll productm (ll x, ll y, ll m) 
{ 
    if (x < y) return productm (y, x, m);
    if (y == 0) return 0;
    ll p = 0;
    while (y)
    {
        if (y & 1) p = ((p % m) + (x % m)) % m;
        x = ((x % m) + (x % m)) % m;
        y >>= 1;
    }
    return p;
}
ll powerr (ll a, ll b, ll c)
{
    ll v = 1;
    while (b)
    {
        if (b & 1) v = productm ((v % c), (a % c), c) % c;
        a = productm ((a % c), (a % c), c) % c;
        b >>= 1;
    }
    return (v + c) % c;
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll a, b, c;
    cin >> a >> b >> c;
    ll x = powerr (a, b, c) % c;
    ll y = productm (a, b, c) % c;
    ll mmib = powerr (b, c - 2, c) % c;
    ll z = productm (a, mmib, c) % c;
    cout << x  << "\n" << y << "\n" << z;
}
