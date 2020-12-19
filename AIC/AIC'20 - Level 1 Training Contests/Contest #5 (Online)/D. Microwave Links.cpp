//https://codeforces.com/group/aDFQm4ed6d/contest/273592/problem/D
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
    for (ll i = 0; i < n - 1; ++i)
    {
        for (ll j = i + 1; j < n; ++j)
        {
            if (a[i] < a[j]) break;
            else if (a[i] == a[j])
            {
                ans = max (ans, j - i);
                break;
            }
        }
    }
    cout << ans;
}

