//https://vjudge.net/contest/418569#problem/I
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
    ll n;
    cin >> n;
    pair<ll, ll> a[n];
    vector<pair<ll, ll>> v;
    v.push_back ({-10000, 10000});
    for (auto& X : a)
    {
        cin >> X.F >> X.S;
        if (X.F > X.S) swap (X.F, X.S);
    }
    sort (a, a + n);
    for (ll i = 0; i < n; ++i)
    {
        bool chk = 0;
        for (auto& X : v)
        {
            if (a[i].S < X.F || a[i].F > X.S) continue;
            X.F = max (X.F, a[i].F);
            X.S = min (X.S, a[i].S);
            chk = 1;
            break;
        }
        if (!chk) v.push_back ({a[i].F, a[i].S});
    }
    cout << v.size () << "\n";
    for (auto& X : v) cout << X.S << " ";
}

