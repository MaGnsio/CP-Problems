//https://vjudge.net/contest/417978#problem/K
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
    ll n, sx, sy, s = 0;
    pair<ll, ll> p;
    map<pair<ll, ll>, ll> m;
    cin >> n >> sx >> sy;
    pair<ll, ll> a[n];
    for (auto& X : a)
    {
        cin >> X.F >> X.S;
        if (sx - 1 >= 0 && X.F < sx) m[{sx - 1, sy}]++;
        if (sx + 1 <= 1e9 && X.F > sx) m[{sx + 1, sy}]++;
        if (sy - 1 >= 0 && X.S < sy) m[{sx, sy - 1}]++;
        if (sy + 1 <= 1e9 && X.S > sy) m[{sx, sy + 1}]++;
    }
    for (auto& X : m) if (X.S > s) p.F = X.F.F, p.S = X.F.S, s = X.S;
    cout << s << "\n" << p.F << " " << p.S;
}

