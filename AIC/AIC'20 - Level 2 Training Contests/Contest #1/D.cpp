//https://vjudge.net/contest/414669#problem/D
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

bool chk (ll n, ll x, ll k, ll a[])
{
    ll y = 0;
    for (ll i = 0; i < n; ++i)
    {
        y += a[i] / x;
        if (y >= k) return true;
    }
    return y >= k;
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k, sum = 0;
        cin >> n >> k;
        ll a[n];
        for (auto& elem : a)
        {
            cin >> elem;
            if (sum < k) sum += elem;
        }
        sort (a, a + n);
        if (sum < k)
        {
            cout << 0 << "\n";
            continue;
        }
        ll l = 1, r = a[n - 1], mid, ans;
        while (l <= r)
        {
            mid = r + (l - r) / 2;
            if (chk (n, mid, k, a)) l = mid + 1, ans = mid;
            else r = mid - 1;
        }
        cout << ans << "\n";
    }
}

