//https://codeforces.com/group/Rv2Qzg0DgK/contest/292431/problem/A
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
    ll s = 0, e = 0, sum = 0, ans = n + 1;
    while (e < n)
    {
        while (sum < m && e < n) sum += a[e++];
        if (sum >= m && s < n) ans = min (ans, e - s), sum -= a[s++];
    }
    cout << (ans == n + 1 ? -1 : ans);
}

