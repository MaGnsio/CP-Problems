//https://codeforces.com/group/Rv2Qzg0DgK/contest/291373/problem/W
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

bool chk (ll n,ld mid, ll a[], ll b[])
{
    ld l = 0, r = 1e9 + 5;
    for (ll i = 0; i < n; ++i) l = max (l, a[i] - b[i] * mid), r = min (r, a[i] + b[i] * mid);
    return l < r;
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n;
    cin >> n;
    ll a[n], b[n];
    for (auto& elem : a) cin >> elem;
    for (auto& elem : b) cin >> elem;
    ld l = 0, r = 1e9 + 5, mid;
    while ( r - l > 1e-7)
    {
        mid = l + (r - l) / 2;
        if (chk (n, mid, a, b)) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision (7) << l;
}

