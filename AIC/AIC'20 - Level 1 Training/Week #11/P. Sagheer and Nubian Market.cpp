//https://codeforces.com/group/Rv2Qzg0DgK/contest/291373/problem/P
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7, sz = 1e5 + 7;

ll n, s, x, y;
ll a[sz], b[sz];

ll chk (ll mid)
{
    ll cost = 0;
    for (ll i = 0; i < n; ++i) b[i] = a[i] + (i + 1) * mid;
    sort (b, b + n);
    for (ll i = 0; i < mid; ++i) cost += b[i];
    return cost;
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    cin >> n >> s;
    for (ll i = 0; i < n; ++i) cin >> a[i];
    ll l = 0, r = n, mid;
    while (l <= r)
    {
        mid = l + (r - l + 1) / 2;
        if (chk (mid) <= s) l = mid + 1, x = mid, y = chk (mid);
        else r = mid - 1;
    }
    cout << x << " " << y;
}

