//https://codeforces.com/group/aDFQm4ed6d/contest/272911/problem/G
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
    ll n, m, cnt = 0;
    cin >> n >> m;
    ll a[(2 * n) + 2] = {};
    while (m--)
    {
        ll l, r;
        cin >> l >> r;
        a[l + n]++, a[r + n + 1]--;
    }
    for (ll i = 1; i < (2 * n) + 2; ++i) a[i] += a[i - 1];
    for (ll i = 0; i < (2 * n) + 1; ++i)
    {
        if (!a[i])
        {
            while (!a[i] && i < (2 * n) + 1) i++;
            cnt++;
        }
    }
    cout << cnt;
}

