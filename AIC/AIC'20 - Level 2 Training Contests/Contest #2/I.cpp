//https://vjudge.net/contest/415649#problem/I
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
    ll n, m;
    cin >> n >> m;
    ll a[n];
    for (auto& elem : a) cin >> elem;
    for (ll i = 1; i < n; ++i) a[i] += a[i - 1];
    if (n == 1)
    {
        cout << m;
        return 0;
    }
    for (ll i = 0; i < n; ++i)
    {
        if (i == 0) cout << a[n - 1] - a[0] << " ";
        else if (i == n - 1) cout << a[n - 2] << " ";
        else cout << max ({a[i - 1], a[i - 1] + a[n - 1] - a[i] + m, a[n - 1] - a[i]}) << " ";
    }
}

