//https://codeforces.com/group/Rv2Qzg0DgK/contest/290492/problem/K
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
    ll n, x, a, mi = LLONG_MAX, ma = LLONG_MIN, ans = 0;
    map<ll, ll> m;
    cin >> n;
    for (ll i = 0; i < n; ++i)
    {
        cin >> x;
        m[x]++;
        mi = min (mi, x), ma = max (ma, x);
    }
    a = mi + ma;
    for (auto& p : m) ans += p.S * m[a - p.F];
    cout << (ans - (a & 1 ? 0 : m[a / 2])) / 2;
}

