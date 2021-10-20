//https://codeforces.com/gym/102892/problem/4
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, q, cnt = 0;
    cin >> n >> q;
    ll a[n], f[n + 1] = {};
    for (auto& x : a) cin >> x;
    while (q--)
    {
        ll x;
        cin >> x;
        f[0]++, f[x]--;
    }
    for (int i = 1; i < n; ++i) f[i] += f[i - 1];
    for (int i = 0; i < n; ++i)
    {
        if (f[i] >= a[i]) cnt++;
    }
    cout << cnt;
}

