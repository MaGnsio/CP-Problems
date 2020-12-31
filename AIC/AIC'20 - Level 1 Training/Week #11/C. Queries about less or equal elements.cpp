//https://codeforces.com/group/Rv2Qzg0DgK/contest/291373/problem/C
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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (auto& elem : a) cin >> elem;
    for (auto& elem : b) cin >> elem;
    sort (a.begin (), a.end ());
    for (auto& elem : b) cout << upper_bound (a.begin (), a.end (), elem) - a.begin () << " ";
}

