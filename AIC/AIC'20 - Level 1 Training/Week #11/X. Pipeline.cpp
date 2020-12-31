//https://codeforces.com/group/Rv2Qzg0DgK/contest/291373/problem/X
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
    ll n, k;
    cin >> n >> k;
    if (k * (k - 1) / 2 < n - 1)
    {
        cout << -1;
        return 0;
    }
    ll l = 0, r = k - 1, mid, ans;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (((k * (k - 1)) - ((k - mid) * (k - mid - 1))) / 2 >= n - 1) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << ans;
}

