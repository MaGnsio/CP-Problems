//https://vjudge.net/contest/421809#problem/D
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
    ll n, p = 0;
    cin >> n;
    vector<pair<ll, ll>> a, b;
    for (ll i = 1; i <= n; ++i)
    {
        ll x;
        cin >> x;
        if (x > 0) a.push_back ({i, x});
        else b.push_back ({i, -x});
    }
    for (ll i = 0, j = 0; i < b.size (); ++i)
    {
        for (/*HAHA*/ ;j < a.size () && b[i].S; ++j)
        {
            ll d = min (b[i].S, a[j].S);
            b[i].S -= d, a[j].S -= d, p += d * abs (b[i].F - a[j].F);
        }
        if (j && a[j - 1].S) j--;
    }
    cout << p;
}

