//https://vjudge.net/contest/417537#problem/F
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
    ll n, k, ans = 0;
    cin >> n >> k;
    if (!k) return cout << (n * n), 0;
    for (ll i = 1; k + i <= n; ++i)
    {
        ll b = k + i;
        ans += (n / b) * i;
        if (n % b >= k) ans += (n % b) - k + 1;
    }
    cout << ans;
}

