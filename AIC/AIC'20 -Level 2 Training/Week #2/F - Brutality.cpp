//https://vjudge.net/contest/417978#problem/F
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
    string s;
    cin >> n >> k;
    ll a[n];
    for (auto& elem : a) cin >> elem;
    cin >> s;
    for (ll i = 0, j = 0; i < n; i = j)
    {
        while (j < n && s[i] == s[j]) j++;
        sort (a + i, a + j, greater<ll> ());
        for (ll z = i; z < min (j, i + k); ++z) ans += a[z];
    }
    cout << ans;
}

