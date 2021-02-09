//https://codeforces.com/group/aDFQm4ed6d/contest/274872/problem/G
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
    vector<ll> f(200005, 0);
    map<ll, ll> m;
    while (n--)
    {
        ll X;
        cin >> X;
        m[X]++;
    }
    for (auto i = m.begin (); i != m.end (); ++i)
    {
        for (auto j = i; ++j != m.end ();) f[(i -> F) + (j -> F)] += min (i -> S, j -> S);
    }
    for (auto& X : m)  f[X.F + X.F] += (X.S / 2);
    cout << *max_element (f.begin (), f.end ());
}

