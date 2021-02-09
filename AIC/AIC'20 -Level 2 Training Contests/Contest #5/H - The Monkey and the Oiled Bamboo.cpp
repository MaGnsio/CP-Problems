//https://vjudge.net/contest/418569#problem/H
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

bool chk (ll n, ll a[], ll mid)
{
    for (ll i = 0; i < n; ++i)
    {
        if (a[i] < mid) continue;
        if (a[i] == mid) mid--;
        else if (a[i] > mid) return false;
    }
    return true;
}
void solve (ll c)
{
    ll n, cur = 0;
    cin >> n;
    ll a[n];
    for (auto& elem : a) cin >> elem;
    for (ll i = n - 1; i > 0; --i) a[i] -= a[i - 1];
    ll l = 1, r = 10000000, k;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (chk (n, a, mid)) r = mid - 1, k = mid;
        else l = mid + 1;
    }
    cout << "Case " << c << ": " << k << "\n";
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t, c = 0;
    cin >> t;
    while (t--) solve (++c);
}
