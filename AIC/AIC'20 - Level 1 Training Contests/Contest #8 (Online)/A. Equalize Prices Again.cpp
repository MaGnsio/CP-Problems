//https://codeforces.com/group/aDFQm4ed6d/contest/277178/problem/A
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
        ll n, x, s = 0;
        cin >> n;
        for (ll i = 0; i < n; ++i) {cin >> x; s += x;}
        ll p = (s + n - 1) / n;
        cout << p << "\n";
    }
}

