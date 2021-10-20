//https://vjudge.net/contest/419722#problem/R
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, m, g = 0;
    cin >> n >> m;
    ll a[n], b[m];
    for (auto& X : a) cin >> X;
    for (auto& X : b) cin >> X;
    for (ll i = 1; i < n; ++i) g = gcd (g, a[i] - a[i - 1]);
    for (ll i = 0; i < m; ++i)
    {
        if (g % b[i] == 0)
        {
            cout << "YES\n" << a[0] << " " << i + 1;
            return 0;
        }
    }
    cout << "NO";
}

