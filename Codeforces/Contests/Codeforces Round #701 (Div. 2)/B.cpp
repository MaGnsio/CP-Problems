//https://codeforces.com/contest/1485/problem/B
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
    ll n, q, k;
    cin >> n >> q >> k;
    ll a[n];
    for (auto& x : a) cin >> x;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        cout << (a[l - 1] - 1) + (k - a[r - 1]) + 2 * ((a[r - 1] - a[l - 1] + 1) - (r - l + 1)) << "\n";
    }
}

