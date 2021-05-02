//https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d82e6
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

void solve (ll c)
{
    ll n, cnt = 0;
    cin >> n;
    ll a[n];
    for (auto& x : a) cin >> x;
    if (n < 3)
    {
        cout << "Case #" << c << ": " << cnt << "\n";
        return;
    }
    for (ll i = 1; i < n - 1; ++i)
    {
        if (a[i - 1] < a[i] && a[i + 1] < a[i]) cnt++;
    }
    cout << "Case #" << c << ": " << cnt << "\n";
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t, c = 0;
    cin >> t;
    while (t--) solve (++c);
}

