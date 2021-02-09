//https://vjudge.net/contest/416541#problem/I
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

ld s (ll a, ll b, ll c, ll d)
{
    ld ans = sqrt (((a - c) * (a - c)) + ((b - d) * (b - d)));
    return ans;
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, x, y;
    cin >> n;
    vector<ll> a, b;
    vector<ld> ans;
    for (ll i = 0; i < n; ++i)
    {
        cin >> x >> y;
        if (x) a.push_back (x);
        if (y) b.push_back (y);
    }
    sort (a.begin (), a.end ());
    sort (b.begin (), b.end ());
    if (a.size () > 1) ans.push_back (s (a[a.size () - 1], 0, a[0], 0));
    if (b.size () > 1) ans.push_back (s (0, b[b.size () - 1], 0, b[0]));
    if (a.size () > 0 && b.size () > 0) ans.push_back (s (a[0], 0, 0, b[0]));
    if (a.size () > 0 && b.size () > 0) ans.push_back (s (a[0], 0, 0,b[b.size () - 1]));
    if (a.size () > 0 && b.size () > 0) ans.push_back (s (a[a.size () - 1], 0, 0, b[0]));
    if (a.size () > 0 && b.size () > 0) ans.push_back (s (a[a.size () - 1], 0, 0, b[b.size () - 1]));
    cout << fixed << setprecision (6) << *max_element (ans.begin (), ans.end ());
}

