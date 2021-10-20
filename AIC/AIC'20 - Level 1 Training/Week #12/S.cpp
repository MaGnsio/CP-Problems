//https://codeforces.com/group/Rv2Qzg0DgK/contest/292431/problem/S
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
    for (ll i = 1; i < n; ++i) a[i] += a[i - 1];
    for (ll i = 0, j = n - 1; i <= j;)
    {
        ll sum1 = a[i], sum2 = a[j] - a[i], sum3 = a[n - 1] - a[j];
        if (sum1 == sum3) ans = max (ans, sum1), i++, j--;
        else if (sum1 < sum3) i++;
        else j--;
    }
    cout << ans;
}

