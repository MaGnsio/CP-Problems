//https://codeforces.com/group/aDFQm4ed6d/contest/296501/problem/G
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
    ll n, ans = 0;
    cin >> n;
    ll a[n];
    for (auto& x : a) cin >> x;
    set<ll> s;
    s.insert (a[0]);
    for (ll i = 1; i < n; ++i)
    {
        ans = max (ans, a[i] - *s.begin ());
        s.insert (a[i]);
    }
    cout << ans;
}

