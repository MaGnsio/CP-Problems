//https://codeforces.com/group/aDFQm4ed6d/contest/296501/problem/J
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7, sz = 1e5 + 1;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, c, curr = 0;
    vector<ll> s (sz, 0), e (sz, 0);
    cin >> n >> c;
    for (ll i = 0; i < n; ++i)
    {
        ll k, l, r;
        cin >> k >> l >> r;
        s[l] += k, e[r] += k;
    }
    for (ll i = 0; i < sz; ++i)
    {
        curr = curr - e[i] + s[i];
        if (curr > c) return cout << "NO", 0;
    }
    cout << "YES";
}

