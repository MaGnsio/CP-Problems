//https://codeforces.com/group/aDFQm4ed6d/contest/298276/problem/L
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
    ll n, ans = 1;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for (auto& x : v) cin >> x.F >> x.S;
    sort (v.begin (), v.end ());
    for (ll i = 0; i < n; ++i)
    {
        ll l = v[i].F, r = v[i].S;
        while (i + 1 < n && !(l > v[i + 1].S || v[i + 1].F > r))
        {
            l = min (l, v[i + 1].F);
            r = max (r, v[i + 1].S);
            i++;
        }
        ans = max (ans, r - l + 1);
    }
    cout << ans;
}

