//https://codeforces.com/group/Rv2Qzg0DgK/contest/290492/problem/N
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

ll search (const vector<pair<ll, ll>> &a, ll x)
{
    ll idx = -1;
    for (ll i = 0; i < a.size (); ++i)
    {
        if (a[i].F > x) break;
        if (idx == -1 || a[i].S > a[idx].S) idx = i;
    }
    return idx;
}
ll solve (ll x, vector<pair<ll, ll>> &v1, vector<pair<ll, ll>> &v2)
{
    ll cnt = 0, idx;
    vector<pair<ll, ll>> a = v1, b = v2;
    while (true)
    {
        if (a.empty ()) break;
        idx = search (a, x);
        if (idx == -1) break;
        x += a[idx].S;
        a.erase (a.begin () + idx);
        cnt++;
        if (b.empty ()) break;
        idx = search (b, x);
        if (idx == -1) break;
        x += b[idx].S;
        b.erase (b.begin () + idx);
        cnt++;
    }
    return cnt;
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, x;
    cin >> n >> x;
    vector<pair<ll, ll>> a, b;
    for (ll i = 0; i < n; ++i)
    {
        ll t, h, m;
        cin >> t >> h >> m;
        if (t) a.push_back ({h, m});
        else b.push_back ({h , m});
    }
    sort (a.begin (), a.end ());
    sort (b.begin (), b.end ());
    cout << max (solve (x, a, b), solve (x, b, a));
}

