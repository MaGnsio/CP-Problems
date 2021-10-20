//https://codeforces.com/group/Rv2Qzg0DgK/contest/292431/problem/I
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
    ll n, m, ans = 0;
    cin >> n;
    ll a[n];
    for (auto& elem : a) cin >> elem;
    sort (a, a + n);
    cin >> m;
    ll b[m];
    for (auto& elem : b) cin >> elem;
    sort (b, b + m);
    for (ll i = 0, j = 0; i < n && j < m;)
    {
        if (abs (a[i] - b[j]) < 2) i++, j++, ans++;
        else if (a[i] < b[j]) i++;
        else j++;
    }
    cout << ans;
}

