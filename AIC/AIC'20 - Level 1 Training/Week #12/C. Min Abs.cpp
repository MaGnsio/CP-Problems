//https://codeforces.com/group/Rv2Qzg0DgK/contest/292431/problem/C
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
    ll n;
    cin >> n;
    ll a[n];
    for (auto& elem : a) cin >> elem;
    sort (a, a + n);
    ll s = 0, e = n - 1, ans = abs (a[s] + a[e]);
    while (s <= e)
    {
        if (a[s] + a[e] > 0) e--;
        else s++;
        ans = min (ans, abs (a[s] + a[e]));
    }
    cout << ans;
}

