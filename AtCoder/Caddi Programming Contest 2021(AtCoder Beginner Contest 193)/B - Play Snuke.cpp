//https://atcoder.jp/contests/abc193/tasks/abc193_b
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
    vector<pair<ll, pair<ll, ll>>> v(n);
    for (auto& x : v) cin >> x.S.F >> x.F >> x.S.S;
    sort (v.begin (), v.end ());
    for (auto& x : v) if (x.S.S - x.S.F > 0) return cout << x.F, 0;
    cout << -1;
}

