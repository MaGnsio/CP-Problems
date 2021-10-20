//https://codeforces.com/gym/102892/problem/7
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
    ll n, cnt = 0;
    cin >> n;
    vector<ll> v (n);
    map<ll, ll> m;
    for (auto& x : v)
    {
        cin >> x;
        x = __builtin_ctz (x);
    }
    for (ll i = 0; i < n; ++i)
    {
        for (auto& x : m) if (x.F < v[i]) cnt += x.S;
        m[v[i]]++;
    }
    cout << cnt;
}

