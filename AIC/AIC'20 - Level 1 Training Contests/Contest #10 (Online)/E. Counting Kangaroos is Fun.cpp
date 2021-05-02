//https://codeforces.com/group/aDFQm4ed6d/contest/279152/problem/E
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
    cin >> n;
    ll a[n];
    for (auto& x : a) cin >> x;
    sort (a, a + n);
    ll l = 0, r = n / 2, ans = n;
    while (l < n / 2 && r < n)
    {
        if (a[l] * 2 <= a[r]) ans--, l++, r++;
        else r++;
    }
    cout << ans;
}

