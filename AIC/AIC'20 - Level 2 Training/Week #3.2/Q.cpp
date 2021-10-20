//https://vjudge.net/contest/419723#problem/Q
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7, mx = 1e18;

vector<ll> dp;

ll root (ll x)
{
    ll l = 0, r = 1e9 + 1;
    while (l < r - 1)
    {
        ll mid = l + (r - l) / 2;
        if (mid * mid == x) return mid;
        if (mid * mid > x) r = mid;
        else l = mid;
    }
    return l;
}
void init ()
{
    vector<ll> temp = {1};
    for (ll i = 2; i <= 1e6; ++i)
    {
        for (ll j = i * i * i; j <= mx; j *= i)
        {
            temp.push_back (j);
            if (j > mx / i) break;
        }
    }
    sort (temp.begin (), temp.end ());
    temp.erase (unique (temp.begin (), temp.end ()), temp.end ());
    for (auto& x : temp)
    {
        ll sq = root (x);
        if (sq * sq == x) continue;
        dp.push_back (x);
    }
}
void solve ()
{
    ll l, r;
    cin >> l >> r;
    ll ans = upper_bound (dp.begin (), dp.end (), r) - lower_bound (dp.begin (), dp.end (), l);
    ans += root (r) - root (l - 1);
    cout << ans << "\n";
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    init ();
    ll t;
    cin >> t;
    while (t--)
        solve ();
}

