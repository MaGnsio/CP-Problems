//https://vjudge.net/contest/416254#problem/Z
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

void solve ()
{
    ll n;
    cin >> n;
    ll a[n];
    for (auto& elem : a) cin >> elem;
    unordered_set<ll> s, cur;
    s.insert (a[0]);
    cur.insert (a[0]);
    for (ll i = 1; i < n; ++i)
    {
        if (a[i] == a[i-1]) continue;
        unordered_set<ll> ts = {a[i]};
        for (auto& x : cur) ts.insert (x | a[i]);
        cur = ts;
        s.insert (cur.begin (), cur.end ());
    }
    cout << s.size () << "\n";
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--) solve ();
}
