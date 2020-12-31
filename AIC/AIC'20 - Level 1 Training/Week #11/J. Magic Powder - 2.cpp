//https://codeforces.com/group/Rv2Qzg0DgK/contest/291373/problem/J
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

bool chk (ll size, ll magic_powder, ll amount_of_cake, ll a[], ll b[])
{
    ll amount_of_magic_powder = 0;
    for (ll i = 0; i < size; ++i)
    {
        amount_of_magic_powder += max (a[i] * amount_of_cake - b[i], 0ll);
        if (amount_of_magic_powder > magic_powder) return false;
    }
    return amount_of_magic_powder <= magic_powder;
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, k, l = 0, r = 2'000'000'000, ans = 0, mid;
    cin >> n >> k;
    ll a[n], b[n];
    for (auto& elem : a) cin >> elem;
    for (auto& elem : b) cin >> elem;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (chk (n, k, mid, a, b)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << ans;
}

