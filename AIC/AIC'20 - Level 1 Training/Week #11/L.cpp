//https://codeforces.com/group/Rv2Qzg0DgK/contest/291373/problem/L
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

bool chk (ll block, ll row) {return row * (row + 1) / 2 >= block;}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--)
    {
       ll n, l = 1, r = 1'414'213'562, mid, ans;
       cin >> n;
       while (l <= r)
       {
            mid = l + (r - l) / 2;
            if (chk (n, mid)) r = mid - 1, ans = mid;
            else l = mid + 1;
       }
       cout << ans << "\n";
    }
}

