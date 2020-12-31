//https://codeforces.com/group/Rv2Qzg0DgK/contest/291373/problem/N
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

bool chk (ll n, ll k, ll mid, ll a[])
{
    ll k_ = 1, s = a[0];
    for (ll i = 1; i < n; ++i)
    {
        if ((a[i] - s + 1) <= mid) continue;
        else k_++, s = a[i];
        if (k_ > k) return false;
    }
    return k_ <= k;
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll a[n];
        for (auto& elem : a) cin >> elem;
        ll l = 1, r = 1e9, mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (chk (n, k, mid, a)) r = mid - 1;
            else l = mid + 1;
        }
        cout << l << "\n";
    }
}

