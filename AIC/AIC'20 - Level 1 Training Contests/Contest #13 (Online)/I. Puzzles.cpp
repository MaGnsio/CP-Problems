//https://codeforces.com/group/aDFQm4ed6d/contest/286323/problem/I
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
    ll n, m, ans = LLONG_MAX;
    cin >> n >> m;
    ll a[m];
    for (auto& x : a) cin >> x;
    sort (a, a + m);
    for (ll i = n - 1; i < m; ++i) ans = min (ans, a[i] - a[i - n + 1]);
    cout << ans;
}

