//https://vjudge.net/contest/418569#problem/E
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

void solve ()
{
    ll n, t, m, x = 0;
    cin >> n >> t >> m;
    ll a[m];
    for (auto& X : a) cin >> X;
    ll y = (m + n - 1) / n;
    t *= 2;
    for (ll i = (m + n - 1) % n; i < m; i += n) x = (a[i] > x ? a[i] : x) + t;
    cout << x - (t / 2) << " " << y << "\n";
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--) solve ();
}

