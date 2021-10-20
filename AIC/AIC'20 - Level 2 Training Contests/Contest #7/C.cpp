//https://vjudge.net/contest/421809#problem/C
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
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto& x : v) cin >> x;
    sort (v.begin (), v.end ());
    for (ll i = 0; i < n - 1; ++i)
    {
        if (v[i] * 2 > v[i + 1] && v[i] != v[i + 1]) return cout << "YES", 0;
    }
    cout << "NO";
}

