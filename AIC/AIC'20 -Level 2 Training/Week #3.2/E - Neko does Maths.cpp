//https://vjudge.net/contest/419723#problem/E
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
    ll a, b;
    pair<ll, ll> c = {LLONG_MAX, LLONG_MAX};
    vector<ll> v;
    cin >> a >> b;
    if (a == b) return cout << 0, 0;
    for (ll i = 1; i * i <= abs (a - b); ++i)
    {
        if (abs (a - b) % i == 0)
        {
            v.push_back (i);
            if (abs (a - b) / i != i) v.push_back (abs (a - b) / i);
        }
    }
    sort (v.begin (), v.end ());
    for (auto& x : v)
    {
        ll d = (x - a % x) % x;
        pair<ll, ll> temp = {((a + d) / gcd (a + d, b + d)) * (b + d), d};
        c = min (c, temp);
    }
    cout << c.S;
}

