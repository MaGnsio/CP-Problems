//https://vjudge.net/contest/414669#problem/H
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
    ll n, m, x;
    cin >> n;
    ll a[n];
    for (auto& elem : a) cin >> elem;
    cin >> m;
    set<ll> b;
    while (m--)
    {
        cin >> x;
        b.insert (x);
    }
    for (auto& elem : a) if (b.count (elem) == 0) cout << elem << " ";
}

