//https://vjudge.net/contest/419722#problem/S
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

ll gcd (ll a, ll b)
{
    if (b == 0) return a;
    return gcd (b, a % b);
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        if ((x >= z || y >= z) && z % gcd (x, y) == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}

