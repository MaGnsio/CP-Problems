//https://codeforces.com/problemset/problem/1471/A
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void solve ()
{
    ll n, x, a, mi = 0, ma = 0;
    cin >> n >> x;
    while (n--)
    {
        cin >> a;
        mi += a;
        ma += (a + x - 1) / x;
    }
    mi = (mi + x - 1) / x;
    cout << mi << " " << ma << "\n";
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--)
        solve ();
}

