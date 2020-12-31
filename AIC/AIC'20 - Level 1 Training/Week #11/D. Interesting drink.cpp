//https://codeforces.com/group/Rv2Qzg0DgK/contest/291373/problem/D
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
    ll n, q, c;
    cin >> n;
    vector <ll> v(n);
    for (auto& elem : v) cin >> elem;
    sort (v.begin (), v.end ());
    cin >> q;
    while (q--)
    {
        cin >> c;
        cout << upper_bound (v.begin (), v.end (), c) - v.begin () << "\n";
    }
}

