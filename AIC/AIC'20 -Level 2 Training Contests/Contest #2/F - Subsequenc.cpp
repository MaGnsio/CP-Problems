//https://vjudge.net/contest/415649#problem/F
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

bool chk (ll n, ll k, ll mid, ll a[])
{
    ll i = 0, j = mid - 1;
    while (j < n)
    {
        if (a[j] - (i ? a[i - 1] : 0) >= k) return true;
        else i++, j++;
    }
    return false;
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, k;
    while (cin >> n >> k)
    {
        ll a[n];
        for (auto& elem : a) cin >> elem;
        for (ll i = 1; i < n; ++i) a[i] += a[i - 1];
        ll l = 1, r = n, ans = 0;
        while (l <= r)
        {
            ll mid = l + (r - l) / 2;
            if (chk (n, k, mid, a)) r = mid - 1, ans = mid;
            else l = mid + 1;
        }
        cout << ans << "\n";
    }
}

