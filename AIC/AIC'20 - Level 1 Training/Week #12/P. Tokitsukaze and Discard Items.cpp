//https://codeforces.com/group/Rv2Qzg0DgK/contest/292431/problem/P
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
    ll n, m, k, ans = 0, i = 0;
    cin >> n >> m >> k;
    ll a[m];
    for (auto& elem : a) cin >> elem;
    while (i < m)
    {
        //page most right item = page no. * page capacity + no. of discarded items
        ll p = ((a[i] - i - 1) / k + 1) * k + i;
        while (i < m && a[i] <= p) i++;
        ans++;
    }
    cout << ans;
}

