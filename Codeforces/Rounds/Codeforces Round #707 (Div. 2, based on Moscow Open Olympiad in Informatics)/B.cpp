//https://codeforces.com/contest/1501/problem/B
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
    ll a[n + 2] = {};
    for (ll i = 1; i <= n; ++i)
    {
        ll x;
        cin >> x;
        a[i]++;
        a[max (0LL, i - x)]--;
    }
    for (ll i = n; i >= 0; --i) a[i] += a[i + 1];
    for (ll i = 1; i <= n; ++i) cout << (a[i] ? 1 : 0) << " ";
    cout << "\n";
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--)
        solve ();
}

