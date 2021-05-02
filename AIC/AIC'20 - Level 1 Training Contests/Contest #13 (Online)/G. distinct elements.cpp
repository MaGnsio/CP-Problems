//https://codeforces.com/group/aDFQm4ed6d/contest/286323/problem/G
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7, sz = 100001;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, q;
    ll a[sz] = {};
    cin >> n >> q;
    while (n--)
    {
        ll x;
        cin >> x;
        if (!a[x]) a[x]++;
    }
    for (ll i = 1; i < sz; ++i) a[i] += a[i - 1];
    while (q--)
    {
        ll x;
        cin >> x;
        cout << a[x - 1] << " " << a[sz - 1] - a[x] << "\n";
    }

}

