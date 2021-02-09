//https://vjudge.net/contest/416254#problem/Y
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

void solve ()
{
    ll n, sum = 0, p = 1;
    cin >> n;
    ll a[n], b[21] = {};
    for (auto& elem : a) cin >> elem;
    for (ll i = 0; i < 21; ++i)
    {
        ll cnt = 0;
        for (ll j = 0; j < n; ++j)
        {
            if (a[j] & (1LL << i)) cnt++;
            else sum += cnt * (cnt + 1) / 2 * (1LL << i), cnt = 0;
        }
        sum += cnt * (cnt + 1) / 2 * (1LL << i);
    }
    cout << sum << "\n";
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--) solve ();
}

