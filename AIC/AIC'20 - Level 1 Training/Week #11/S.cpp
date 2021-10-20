//https://codeforces.com/group/Rv2Qzg0DgK/contest/291373/problem/S
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

bool chk (string t, string p, ll mid, ll a[])
{
    ll ctr = 0;
    string x = t;
    for (ll i = 0; i < mid; ++i) x[a[i] - 1] = '0';
    for (ll i = 0; i < t.size (); ++i)
    {
        if (x[i] == p[ctr]) ctr++;
        if (ctr >= p.size ()) return true;
    }
    return ctr >= p.size ();
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    string t, p;
    cin >> t >> p;
    ll a[t.size ()];
    for (auto& elem : a) cin >> elem;
    ll l = 0, r = t.size () - p.size (), mid, ans = 0;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (chk (t, p, mid, a)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << ans;
}

