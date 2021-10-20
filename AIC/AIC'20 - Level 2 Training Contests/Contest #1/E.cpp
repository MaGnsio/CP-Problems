//https://vjudge.net/contest/414669#problem/E
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

bool comp (tuple<ll, ll, ll> a, tuple<ll, ll, ll> b)
{
 return ((get<0> (a) < get<0> (b))
       ||(get<0> (a) == get<0> (b) && get<1> (a) < get<0> (b)));
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x, y;
        cin >> n;
        tuple<ll, ll, ll> m[3 * n];
        for (ll i = 0; i < 3 * n; ++i)
        {
            cin >> x >> y;
            auto k = make_tuple (x, y, i + 1);
            m[i] = k;
        }
        sort (m, m + (3 * n), comp);
        for (ll i = 0; i < 3 * n; i += 3) cout << get<2> (m[i]) << " " << get<2> (m[i + 1]) << " " << get<2> (m[i + 2]) << "\n";
    }
}

