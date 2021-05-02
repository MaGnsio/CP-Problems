//https://codeforces.com/group/aDFQm4ed6d/contest/298276/problem/C
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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b;
    for (auto& x : a) cin >> x;
    for (ll i = 0; i < n; ++i)
    {
        ll temp = 0;
        for (ll j = i; j < n; ++j)
        {
            temp += a[j];
            b.push_back (temp);
        }
    }
    sort (b.begin (), b.end (), greater<ll> ());
    for (ll i = 0; i < k; ++i) cout << b[i] << " ";
}

