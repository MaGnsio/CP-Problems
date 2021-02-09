//https://vjudge.net/contest/420442#problem/G
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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(m), b(k), c;
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    ll mi = k, cur;
    for (ll i = 0; i < m; ++i)
    {
        ll cnt = 0;
        for (ll j = 0; j < k; ++j) if (b[j] % a[i] == 0) cnt++;
        if (cnt < mi) mi = cnt;
        a[i] = cnt;
    }
    for (ll i = 0; i < m; ++i)
    {
        if (a[i] == mi) c.push_back (i + 1);
    }
    cout << c.size () << "\n";
    for (auto& x : c) cout << x << " ";
}

