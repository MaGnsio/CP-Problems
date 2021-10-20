//https://codeforces.com/group/aDFQm4ed6d/contest/287062/problem/F
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
    ll a[n];
    for (auto& x : a) cin >> x;
    ll sum = 0;
    for (ll i = 0; i < n; ++i)
    {
        sum += a[i];
        if (sum <= 0)
        {
            cout << "NO\n";
            return;
        }
    }
    sum = 0;
    for (ll i = n - 1; i >= 0; --i)
    {
        sum += a[i];
        if (sum <= 0)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--)
        solve ();
}

