//https://codeforces.com/group/Rv2Qzg0DgK/contest/291373/problem/B
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
    ll n, q, x;
    cin >> n >> q;
    vector<ll> v(n);
    for (auto& elem : v) cin >> elem;
    sort (v.begin (), v.end ());
    while (q--)
    {
        cin >> x;
        cout << (upper_bound (v.begin (), v.end (), x) == v.end () ? -1 : *upper_bound (v.begin (), v.end (), x)) << "\n";
    }
}

