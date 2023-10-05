//https://codeforces.com/contest/1501/problem/A
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void solve ()
{
    ll n;
    cin >> n;
    ll a[n], b[n], c[n];
    for (ll i = 0; i < n; ++i) cin >> a[i] >> b[i];
    for (ll i = 0; i < n; ++i) cin >> c[i];
    ll l = 0, d = 0, t = 0;
    for (ll i = 0; i < n; ++i)
    {
        t = a[i] + c[i] + d;
        l = max (b[i], t + (b[i] - a[i] + 1) / 2);
        d = l - b[i];
    }
    cout << t << "\n";
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--)
        solve ();
}

