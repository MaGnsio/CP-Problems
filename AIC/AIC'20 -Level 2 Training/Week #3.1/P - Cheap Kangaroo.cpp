//https://vjudge.net/contest/419722#problem/P
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

void solve ()
{
    ll n, s = 0;
    cin >> n;
    ll a[n];
    for (auto& X : a) {cin >> X; s += X;}
    if (n == 1)
    {
        cout << s << " " << s << "\n";
        return;
    }
    ll g = gcd (a[0], a[1]);
    for (ll i = 2; i < n; ++i) g = gcd (g, a[i]);
    cout << s << " " << g << "\n";
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--) solve ();
}

