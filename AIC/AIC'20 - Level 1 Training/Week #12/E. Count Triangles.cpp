//https://codeforces.com/group/Rv2Qzg0DgK/contest/292431/problem/E
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
    ll n, ans = 0;
    cin >> n;
    ll a[n];
    for (auto& elem : a) cin >> elem;
    sort (a, a + n);
    for (ll i = n - 1; i > 1; --i)
    {
        ll l = 0, r = i - 1;
        while (l < r)
        {
            if (a[l] + a[r] > a[i]) ans += r - l, r--;
            else l++;
        }
    }
    cout << ans;
}

