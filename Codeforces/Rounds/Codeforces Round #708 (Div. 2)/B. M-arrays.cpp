//https://codeforces.com/contest/1497/problem/B
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void solve ()
{
    ll n, m, cnt = 0;
    cin >> n >> m;
    ll a[m] = {};
    for (ll i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        a[x % m]++;
    }
    if (a[0] != 0)
    {
        cnt++;
        a[0] = 0;
    }
    if (m % 2 == 0 && a[m / 2] != 0)
    {
        cnt++;
        a[m / 2] = 0;
    }
    for (ll i = 1; i < (m / 2 + m % 2); ++i)
    {
        if (!a[i] && !a[m - i]) continue;
        ll temp = min (a[i], a[m - i]);
        a[i] -= temp;
        a[m - i] -= temp;
        if (a[i]) a[i]--;
        if (a[m - i]) a[m - i]--;
        cnt++;
    }
    for (auto& x : a) cnt += x;
    cout << cnt << "\n";
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--)
        solve ();
}

