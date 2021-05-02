//https://codeforces.com/group/aDFQm4ed6d/contest/288718/problem/I
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

bool isprime (ll n)
{
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0)
    {
        return false;
    }
    return true;
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        cout << (a - b == 1 && isprime (a + b) ? "YES" : "NO") << "\n";
    }
}

