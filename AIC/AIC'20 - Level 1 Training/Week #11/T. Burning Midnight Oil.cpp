//https://codeforces.com/group/Rv2Qzg0DgK/contest/291373/problem/T
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
    ll l = 1, r = n, mid, ans;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        ll p = 1, chk = 0;
        while (mid / p) chk += (mid / p), p *= k;
        if (chk == n)
        {
            ans = mid;
            break;
        }
        if (chk > n) r = mid - 1, ans = mid;
        if (chk < n) l = mid + 1;
    }
    cout << ans;
}

