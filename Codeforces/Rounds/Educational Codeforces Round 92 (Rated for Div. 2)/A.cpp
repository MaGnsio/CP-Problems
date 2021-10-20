//https://codeforces.com/problemset/problem/1389/A
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
    ll t;
    cin >> t;
    while (t--)
    {
        ll l, r, x = -1, y = -1;
        cin >> l >> r;
        if (2 * l <= r) x = l, y = 2 * l;
        cout << x << " " << y << "\n";
    }
}

