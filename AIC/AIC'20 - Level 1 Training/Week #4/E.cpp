//https://codeforces.com/group/Rv2Qzg0DgK/contest/273155/problem/E
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
    ll y, k, n;
    vector<ll> v;
    cin >> y >> k >> n;
    for (ll i = k - (y % k); i + y <= n; i += k)
    {
        if ((i + y) % k == 0) v.push_back (i);
    }
    if (v.empty ()) cout << -1;
    else for (auto& elem : v) cout << elem << " ";
}

