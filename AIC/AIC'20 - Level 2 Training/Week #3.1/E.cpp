//https://vjudge.net/contest/419722#problem/E
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

void solve (ll c)
{
    function<bool (ll)> f = [] (ll x) {for (ll i = 2; i * i <= x; ++i) if (x % i == 0) return false; return true;};
    ll n, k, s = 1, cnt = 0;
    cin >> n >> k;
    ll a[k];
    for (auto& X : a) cin >> X;
    for (ll i = 1; i <= n; ++i)
    {
        if (f (i)) continue;
        ll chk = true;
        for (auto& X : a) if (i % X == 0)
        {
            chk = false;
            break;
        }
        if (chk) cnt++;
    }
    cout << "Case " << c << ": " << cnt << "\n";
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t, c = 0;
    cin >> t;
    while (t--) solve (++c);
}

