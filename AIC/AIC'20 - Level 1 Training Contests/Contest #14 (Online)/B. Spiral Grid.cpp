//https://codeforces.com/group/aDFQm4ed6d/contest/287062/problem/B
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7, mx = 1e10;

ll findInGrid (ll i, ll j)
{
    if (i == j) return (i * i - (i - 1));
    else if (i > j)
    {
        if (i % 2 == 0) return i * i - (j - 1);
        else return (i - 1) * (i - 1) + 1 + (j - 1);
    }
    else
    {
        if (j % 2 == 0) return (j - 1) * (j - 1) + 1 + (i - 1);
        else return j * j - (i - 1);
    }
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll i, j;
        cin >> i >> j;
        cout << findInGrid (i, j) << "\n";
    }
}

