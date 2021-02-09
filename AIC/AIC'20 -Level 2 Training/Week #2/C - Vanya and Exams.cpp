//https://vjudge.net/contest/417978#problem/C
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
    ll n, r, v, s = 0;
    cin >> n >> r >> v;
    pair<ll, ll> a[n];
    for (auto& X : a)
    {
        cin >> X.S >> X.F;
        s += X.S;
    }
    sort (a, a + n);
    ll g = n * v - s, e = 0, cnt = 0;
    if (g <= 0) return cout << 0, 0;
    for (ll i = 0; i < n; ++i)
    {
        if (cnt == g) break;
        ll temb = min (g - cnt, r - a[i].S);
        e += temb * a[i].F, cnt += temb;
    }
    cout << e;
}

