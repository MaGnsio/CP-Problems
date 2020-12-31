//https://codeforces.com/group/Rv2Qzg0DgK/contest/291373/problem/R
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
 
bool chk (ll t, ll m) {return 3 * (m * (m + 1) / 2) <= t;}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll h, n, k;
    cin >> h >> n >> k;
    ll t = (h * 60) - k, l = 1, r = n, mid, ans;
    if (t < 3)
    {
        cout << 0;
        return 0;
    }
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (chk (t, mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << ans;
}
