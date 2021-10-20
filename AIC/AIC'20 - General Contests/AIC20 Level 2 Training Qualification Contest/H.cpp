//https://codeforces.com/group/nVgev28wQI/contest/308101/problem/H
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
    //preprocessing
    const ll sz = 1'000'01;
    bitset<sz> b;
    vector<int> v(sz, 0);
    b.set ();
    for (ll i = 2; i * i <= sz; ++i)
    {
        if (b[i])
        {
            for (ll j = i * i; j < sz; j += i) b[j] = false;
        }
    }
    for (ll i = 3; i < sz; ++i) if (b[i] && b[(i + 1) / 2]) v[i] = 1;
    for (ll i = 3; i < sz; ++i) v[i] += v[i - 1];
    //actual problem
    ll t, l, r;
    cin >> t;
    while (t--)
    {
        cin >> l >> r;
        cout << v[r] - v[l - 1] << "\n";
    }
}

