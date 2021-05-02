//https://codeforces.com/group/aDFQm4ed6d/contest/279152/problem/B
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
    ll n, m, t = 0;
    cin >> n >> m;
    ll a[m];
    for (auto& x : a) cin >> x;
    for (ll i = 0; i < m; ++i)
        t += (a[i] >= (i ? a[i - 1] : 1) ? a[i] - (i ? a[i - 1] : 1) : n - (i ? a[i - 1] : 1) + a[i]);
    cout << t;
}

