//https://codeforces.com/contest/1498/problem/A
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

ll sum (ll n)
{
    ll k = 0;
    while (n)
    {
        k += n % 10;
        n /= 10;
    }
    return k;
}

ll gcd (ll a, ll b)
{
    return (b ? gcd (b, a % b) : a);
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll x = n;
        while (gcd (x, sum (x)) <= 1) x++;
        cout << x << "\n";
    }
}

