//https://codeforces.com/group/Rv2Qzg0DgK/contest/273155/problem/I
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
    ll n, k, q, l, r;
    ll a[2'000'002] = {}, b[2'000'002] = {};
    cin >> n >> k >> q;
    while (n--)
    {
        cin >> l >> r;
        a[l]++, a[r + 1]--;
    }
    for (ll i = 1; i < 2'000'002; ++i)
    {
        a[i] += a[i - 1];
        if (a[i] >= k) b[i] = 1;
    }
    for (ll i = 1; i < 2'000'002; ++i) b[i] += b[i - 1];
    while (q--)
    {
        cin >> l >> r;
        cout << b[r] - b[l - 1] << "\n";
    }
}

