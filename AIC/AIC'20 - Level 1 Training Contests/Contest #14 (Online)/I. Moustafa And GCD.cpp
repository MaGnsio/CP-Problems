//https://codeforces.com/group/aDFQm4ed6d/contest/287062/problem/I
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
    ll n, x, g = 1;
    cin >> n;
    while (n--)
    {
        cin >> x;
        g = max (g, x);
    }
    cout << g;
}

