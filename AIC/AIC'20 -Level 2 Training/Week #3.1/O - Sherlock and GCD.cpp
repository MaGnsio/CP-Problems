//https://vjudge.net/contest/419722#problem/O
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
        ll n, x, g = 0;
        cin >> n;
        while (n--) {cin >> x; g = gcd (g, x);}
        cout << (g == 1 ? "YES\n" : "NO\n");
    }
}

