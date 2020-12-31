//https://codeforces.com/group/Rv2Qzg0DgK/contest/291373/problem/K
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

bool chk (ll size, ll cuts,ll log, ll a[])
{
    ll cuts_needed = 0;
    for (ll i = 0; i < size; ++i)
    {
        cuts_needed += (a[i] - 1) / log;
        if (cuts_needed > cuts) return false;
    }
    return cuts_needed <= cuts;
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, k, ans = 1;
    cin >> n >> k;
    ll a[n];
    for (auto& elem : a) cin >> elem;
    ll l = 1, r = *max_element (a, a + n), mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (chk (n, k, mid, a)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << ans;
}

