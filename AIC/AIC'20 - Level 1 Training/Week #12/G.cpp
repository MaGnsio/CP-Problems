//https://codeforces.com/group/Rv2Qzg0DgK/contest/292431/problem/G
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
    ll n, d;
    cin >> n >> d;
    ll a[n];
    for (auto& elem : a) cin >> elem;
    ll l = 0, r = 2, ans = 0;
    while (l < n - 2 && r < n)
    {
        if (a[r] - a[l] <= d) ans += (r - l - 1) * (r - l) / 2, r++;
        else l++;
    }
    cout << ans;
}

