//https://vjudge.net/contest/419722#problem/G
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
    ll n, x, sz = 1'000'000;
    vector<ll> d(sz, 0), f(sz, 0);
    cin >> n;
    d[0] = n;
    for (ll i = 0; i < n; ++i) {cin >> x; f[x - 1]++;}
    for (ll i = 2; i <= sz; ++i)
    {
        for (ll j = i; j <= sz; j += i) d[i - 1] += f[j - 1];
    }
    for (auto& X : d) cout << X << "\n";
}

