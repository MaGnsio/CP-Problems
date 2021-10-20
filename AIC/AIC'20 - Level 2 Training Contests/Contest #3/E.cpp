//https://vjudge.net/contest/416541#problem/E
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
    ll a[n];
    for (auto& elem : a) cin >> elem;
    sort (a, a + n);
    while (a[0] != k)
    {
        for (ll i = 0; i < n; ++i)
        {
            if (a[i] == a[i + 1] && i != n - 1) continue;
            if (a[i] < k) a[i]++;
        }
        ans++;
    }
    cout << ans;
}

