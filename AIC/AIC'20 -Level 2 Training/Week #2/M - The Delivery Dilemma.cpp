//https://vjudge.net/contest/417978#problem/M
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

void solve ()
{
    ll n, t = 0;
    cin >> n;
    pair<ll, ll> a[n];
    for (auto& X : a) cin >> X.F;
    for (auto& X : a) cin >> X.S;
    sort (a, a + n, greater<pair<ll, ll>> ());
    for (ll i = 0; i < n; ++i)
    {
        if (a[i].F < a[i].S + t)
        {
            t = max (t, a[i].F);
            break;
        }
        t += a[i].S;
    }
    cout << t << "\n";
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--) solve ();
}

