//https://codeforces.com/group/Rv2Qzg0DgK/contest/290492/problem/M
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
    ll n, cnt = 0;
    cin >> n;
    vector<ll> v(n), p;
    map<ll, ll> m;
    for (ll i = 0; i < 31; ++i) p.push_back (1LL << i);
    for (ll i = 0; i < n; ++i)
    {
        cin >> v[i];
        for (ll j = 0; j < 31; ++j) if (p[j] > v[i]) cnt += m[p[j] - v[i]];
        m[v[i]]++;
    }
    cout << cnt;
}

