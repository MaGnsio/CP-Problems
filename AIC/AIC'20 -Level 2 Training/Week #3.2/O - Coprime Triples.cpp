//https://vjudge.net/contest/419723#problem/O
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7, sz = 1000000;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, ans = 0;
    ll cnt[sz + 1] = {};
    cin >> n;
    for (ll i = 0; i < n; ++i) {ll x; cin >> x; cnt[x]++;}
    for (ll i = 2; i <= sz; ++i)
    {
        int j = i;
        ll ctr = 0;
        while (j <= 1000000)
        {
            ctr += cnt[j];
            j += i;
        }
        int x = i, factors = 0;
        bool chk = true;
        for (int d = 2; d * d <= x; ++d)
        {
            if (x % d == 0)
            {
                x /= d;
                factors++;
                if (x % d == 0)
                {
                    chk = false;
                    break;
                }
            }
        }
        if (!chk) continue;
        if (x > 1) factors++;
        ll v = 1LL * ctr * (ctr - 1) * (ctr - 2) / 6;
        if (factors % 2 == 1) ans += v;
        else ans -= v;
    }
    ll res = n * (n - 1) * (n - 2) / 6 - ans;
    cout << res;
}
