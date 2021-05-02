//https://codeforces.com/group/aDFQm4ed6d/contest/278613/problem/J
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
    ll n, m, h = 0;
    cin >> n >> m;
    ll a[n];
    for (auto& x : a) cin >> x;
    for (ll i = 1; i < n; ++i) a[i] += a[i - 1];
    while (m--)
    {
        ll l, r;
        cin >> l >> r;
        h += max (0ll, a[r - 1] - (l - 2 >= 0 ? a[l - 2] : 0));
    }
    cout << h;
}

