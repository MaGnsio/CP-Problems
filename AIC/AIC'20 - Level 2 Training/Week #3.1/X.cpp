//https://vjudge.net/contest/419722#problem/X
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
    if (n <= 2) return cout << n, 0;
    if (n & 1)
    {
        ll lcm = (n) * (n - 1) * (n - 2);
        cout << lcm;
        return 0;
    }
    ll lcm = (n - 1) * (n - 2) * (n - 3);
    for (ll i = 2; i < n; ++i) lcm = max (lcm, n * (n - 1) * i / (gcd (n, i) * gcd (n - 1, i) * 1ll));
    cout << lcm;
}

