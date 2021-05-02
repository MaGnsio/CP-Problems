//https://codeforces.com/group/aDFQm4ed6d/contest/279676/problem/D
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll x, y;
    cin >> x >> y;
    ll a = (abs (x) + abs (y)) * (x < 0 ? -1 : 1);
    ll b = (abs (x) + abs (y)) * (y < 0 ? -1 : 1);
    pair<ll, ll> o = {a, 0}, p = {0, b};
    if (o.F > p.F) swap (o, p);
    cout << o.F << " " << o.S << " " << p.F << " " << p.S;
}

