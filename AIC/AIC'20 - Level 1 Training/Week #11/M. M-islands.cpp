//https://codeforces.com/group/Rv2Qzg0DgK/contest/291373/problem/M
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    //input number of ships & number of islands
    ll n, m;
    cin >> n >> m;
    //input every ship traffic
    pair<ll, ll> a[n];
    for (auto& elem : a) cin >> elem.F >> elem.S;
    //sort the traffic and connect segments together
    sort (a, a + n);
    vector<pair<ll, ll>> b;
    ll s = a[0].F, e = a[0].S;
    for (ll i = 1; i < n; ++i)
    {
        if (a[i].F <= e) e = max (e, a[i].S);
        else
        {
            b.push_back ({s, e});
            s = a[i].F, e = a[i].S;
        }
    }
    b.push_back ({s, e});
    //for every query search if u & v belongs to the same segment or not
    ll q;
    cin >> q;
    while (q--)
    {
        ll u, v;
        cin >> u >> v;
        ll x = min (u, v), y = max (u, v), l = 0, r = b.size () - 1, mid, in = 0;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (b[mid].F <= x && b[mid].S >= y)
            {
                cout << "YES\n";
                in = 1;
                break;
            }
            if ((b[mid].F <= x && b[mid].S >= x && b[mid].S < y) || (b[mid].F <= y && b[mid].S >= y && b[mid].F > x))
            {
                cout << "NO\n";
                in = 1;
                break;
            }
            if (b[mid].F > x) r = mid - 1;
            else l = mid + 1;
        }
        if (!in) cout << "NO\n";
    }
}

