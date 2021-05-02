//https://codeforces.com/group/aDFQm4ed6d/contest/298276/problem/H
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
    ll n;
    cin >> n;
    ll a[n + 1] = {};
    for (ll i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] == i) a[i] = 1;
        else a[i] = 0;
    }
    ll curr = -1;
    for (ll i = n; i > 0; --i)
    {
        if (a[i] == 1) a[i] = curr = i;
        else a[i] = curr;
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        if (a[l] <= r) cout << a[l] << "\n";
        else cout << -1 << "\n";
    }
}

