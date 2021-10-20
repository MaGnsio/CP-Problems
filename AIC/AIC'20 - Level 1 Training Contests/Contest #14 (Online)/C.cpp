//https://codeforces.com/group/aDFQm4ed6d/contest/287062/problem/C
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
    ll n, k;
    cin >> n >> k;
    ll x = k * max (n, 2ll);
    while (x > mx) x -= k;
    for (ll i = 0; i < n - 1; ++i) cout << 1 << " ";
    cout << x - n + 1;
}

