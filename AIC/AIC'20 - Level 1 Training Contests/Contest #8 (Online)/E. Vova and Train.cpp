//https://codeforces.com/group/aDFQm4ed6d/contest/277178/problem/E
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
    ll t;
    cin >> t;
    while (t--)
    {
        ll d, v, l, r;
        cin >> d >> v >> l >> r;
        ll n = d / v;
        ll x = (r / v) - ((l - 1) / v);
        cout << n - x << "\n";
    }
}

