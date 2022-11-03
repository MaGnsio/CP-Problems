//https://atcoder.jp/contests/abc180/tasks/abc180_c
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
    ll n;
    vector<ll> v;
    cin >> n;
    for (ll i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            v.push_back (i);
            if (i * i != n) v.push_back (n / i);
        }
    }
    sort (v.begin (), v.end ());
    for (auto& x : v) cout << x << "\n";
}

