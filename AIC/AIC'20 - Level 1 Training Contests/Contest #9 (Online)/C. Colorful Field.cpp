//https://codeforces.com/group/aDFQm4ed6d/contest/278613/problem/C
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
    ll n, m, k, t;
    cin >> n >> m >> k >> t;
    vector<pair<ll, ll>> v;
    while (k--)
    {
        ll x, y;
        cin >> x >> y;
        v.push_back ({x, y});
    }
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        ll l = m * (x - 1) + y - 1, r = 0, chk = 0;
        for (ll i = 0; i < v.size (); ++i)
        {
            if (v[i].F == x && v[i].S == y) chk = 1;
            if (v[i].F < x || (v[i].F == x && v[i].S < y)) r++;
        }
        if (chk) cout << "Waste\n";
        else if ((l - r) % 3 == 0) cout << "Carrots\n";
        else if ((l - r) % 3 == 1) cout << "Kiwis\n";
        else cout << "Grapes\n";
    }
}

