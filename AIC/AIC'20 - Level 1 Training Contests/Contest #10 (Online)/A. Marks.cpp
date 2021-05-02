//https://codeforces.com/group/aDFQm4ed6d/contest/279152/problem/A
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
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, vector<ll>>> v(m, {0, {}});
    set<ll> s;
    for (ll i = 1; i <= n; ++i)
    {
        string x;
        cin >> x;
        for (ll j = 0; j < m; ++j)
        {
            if (x[j] - '0' > v[j].F)
            {
                v[j].S.clear ();
                v[j].F = x[j] - '0';
                v[j].S.push_back (i);
            }
            else if (x[j] - '0' == v[j].F) v[j].S.push_back (i);
        }
    }
    for (auto& x : v) for (auto& y : x.S) s.insert (y);
    cout << s.size ();
}

