//https://codeforces.com/contest/1492/problem/B
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
    vector<ll> v(n);
    vector<vector<ll>> a;
    for (auto& x : v) cin >> x;
    for (ll i = 0, j = 0; i < n; ++i)
    {
        ll x = v[i];
        a.push_back ({v[i]});
        while (v[i + 1] < x && i + 1 < n) a[j].push_back (v[i + 1]), i++;
        j++;
    }
    reverse (a.begin (), a.end ());
    for (auto& y : a) for (auto& x : y) cout << x << " ";
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

