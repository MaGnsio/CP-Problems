//https://codeforces.com/group/aDFQm4ed6d/contest/298276/problem/E
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
    ll n, cnt = 0, curr = 0;
    cin >> n;
    vector<ll> a(n), v;
    for (auto& x : a) cin >> x;
    sort (a.begin (), a.end ());
    for (ll i = 0; i < n; ++i) v.push_back (cnt + n - i), cnt += a[i] - curr, curr = a[i];
    v.push_back (cnt - (a[n - 1] - a[n - 2]) + 1);
    sort (v.begin (), v.end ());
    cout << min (cnt, v[0]);
}

