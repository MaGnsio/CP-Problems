//https://vjudge.net/contest/418569#problem/B
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

bool comp (pair<ll, ll> x, pair<ll, ll> y) {return x.S > y.S;};
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, h, maxt = 0, sum = 0, k = 0;
    cin >> n >> h;
    pair<ll, ll> a[n];
    for (auto& X : a) cin >> X.F >> X.S;
    sort (a, a + n, greater<pair<ll, ll>> ());
    maxt = a[0].F;
    sort (a, a + n, comp);
    for (ll i = 0; i < n; ++i)
    {
        if (a[i].S < maxt) break;
        if (sum >= h) return cout << k, 0;
        sum += a[i].S, k++;
    }
    k += (h - sum + maxt - 1) / maxt;
    cout << k;
}

