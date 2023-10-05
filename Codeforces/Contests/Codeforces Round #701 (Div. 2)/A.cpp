//https://codeforces.com/contest/1485/problem/A
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void solve ()
{
    ll a, b, ans;
    cin >> a >> b;
    if (!a)
    {
        cout << 0 << "\n";
        return;
    }
    ans = a + 3;
    for (ll i = (b < 2 ? 2 - b : 0); i < ans; ++i)
    {
        ll x = a, y = b + i, cnt = i;
        while (x)
        {
            x /= y;
            cnt++;
        }
        ans = min (ans, cnt);
    }
    cout << ans << "\n";
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--)
        solve ();
}

