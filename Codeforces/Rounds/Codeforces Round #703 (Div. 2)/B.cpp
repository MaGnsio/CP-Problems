//https://codeforces.com/contest/1486/problem/B
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
    ll x[n], y[n];
    for (ll i = 0; i < n; ++i) cin >> x[i] >> y[i];
    sort (x, x + n);
    sort (y, y + n);
    ll px = x[n / 2] - x[(n - 1) / 2] + 1;
    ll py = y[n / 2] - y[(n - 1) / 2] + 1;
    cout << px * py << "\n";
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--)
        solve ();
}

