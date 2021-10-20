//https://vjudge.net/contest/418569#problem/F
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
    ll n, p = 0, d = 0, l = 0;
    priority_queue<ll> q;
    cin >> n;
    pair<ll, ll> a[n];
    for (auto& X : a) cin >> X.F >> X.S;
    for (ll i = 0; i < n; ++i)
    {
        p += (a[i].F - l), l = a[i].F;
        q.push (a[i].S);
        while (p < a[i].S && !q.empty ())
        {
            ll x = q.top ();
            p += x;
            q.pop ();
            d++;
        }
        p -= a[i].S;
    }
    cout << d;
}

