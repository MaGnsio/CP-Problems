//https://codeforces.com/group/aDFQm4ed6d/contest/296501/problem/F
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

bool chk (ll mid, ll k, ll n, ll a[])
{
    for (ll s = 0, e = mid - 1; e < n; ++s, ++e)
    {
        ll tmp = a[e] - (s ? a[s - 1] : 0);
        if (tmp > k) return false;
    }
    return true;
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (auto& x : a) cin >> x;
    for (ll i = 1; i < n; ++i) a[i] += a[i - 1];
    ll l = 1, r = n, ans = -1;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (chk (mid, k, n, a)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << ans;
}

