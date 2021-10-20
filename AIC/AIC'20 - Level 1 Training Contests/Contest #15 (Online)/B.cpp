//https://codeforces.com/group/aDFQm4ed6d/contest/287686/problem/B
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
    ll n;
    cin >> n;
    ll a[n];
    for (auto& x : a) cin >> x;
    deque<ll> q;
    for (ll i = 0; i < n; ++i)
    {
        if (i & 1) q.push_front (a[i]);
        else q.push_back (a[i]);
    }
    if (n & 1) reverse (q.begin (), q.end ());
    for (auto& x : q) cout << x << " ";
}

