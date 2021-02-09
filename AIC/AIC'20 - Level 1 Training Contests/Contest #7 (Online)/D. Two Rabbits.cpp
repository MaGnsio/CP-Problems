//https://codeforces.com/group/aDFQm4ed6d/contest/275835/problem/D
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
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        ll n = (y - x) / (a + b);
        if ((n * a) + x == y - (n * b)) cout << n << "\n";
        else cout << -1 << "\n";
    }
}

