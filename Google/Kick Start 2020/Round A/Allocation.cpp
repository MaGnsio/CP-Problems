//https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f56
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

void solve (ll c)
{
    ll n, b;
    cin >> n >> b;
    ll a[n];
    for (auto& x : a) cin >> x;
    sort (a, a + n);
    for (ll i = 0; i < n; ++i)
    {
        if (a[i] > b)
        {
            cout <<  "Case #" << c << ": " << i << "\n";
            return;
        }
        b -= a[i];
    }
    cout <<  "Case #" << c << ": " << n << "\n";
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t, c = 0;
    cin >> t;
    while (t--) solve (++c);
}

