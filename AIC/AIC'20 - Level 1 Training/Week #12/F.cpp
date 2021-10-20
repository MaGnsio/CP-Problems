//https://codeforces.com/group/Rv2Qzg0DgK/contest/292431/problem/F
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
    ll n;
    cin >> n;
    ll a[n];
    for (auto& elem : a) cin >> elem;
    ll j = 0, ans = 0;
    map<ll, ll> m;
    for (ll i = 0; i < n; ++i)
    {
        while (j < n && !m[a[j]]) m[a[j++]]++;
        ans += j - i, m[a[i]]--;
    }
    cout << ans;
}
