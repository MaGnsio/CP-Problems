//https://codeforces.com/group/aDFQm4ed6d/contest/296501/problem/C
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
    ll n, l = 0;
    cin >> n;
    ll a[n];
    for (auto& x : a) cin >> x;
    vector<pair<ll, ll>> v;
    unordered_set<ll> s;
    for (ll i = 0; i < n; ++i)
    {
        s.insert (a[i]);
        if (s.size () < i - l + 1)
        {
            v.push_back ({l + 1, i + 1});
            l = i + 1;
            s.clear ();
        }
    }
    if (v.empty ()) return cout << -1, 0;
    v[v.size () - 1].S = n;
    cout << v.size () << "\n";
    for (auto& x : v) cout << x.F << " " << x.S << "\n";
}

