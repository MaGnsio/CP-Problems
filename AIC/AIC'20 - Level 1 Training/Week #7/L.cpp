//https://codeforces.com/group/Rv2Qzg0DgK/contest/285699/problem/L
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
    int n, m, maz = 0, miz = 0;
    cin >> n >> m;
    int a[m];
    for (auto& elem : a) cin >> elem;
    sort (a, a + m);
    ll i = 0, c = 0;
    while (c < n && i < m)
    {
        miz += (a[i] * (a[i] + 1) / 2) - (c + a[i] > n ? (c + a[i] - n) * (c + a[i] - n + 1) / 2 : 0);
        c += a[i], i++;
    }
    c = 0;
    while (c < n && count (a, a + m, 0) != m)
    {
        maz += *max_element (a, a + m);
        *max_element (a, a + m) = *max_element (a, a + m) - 1, c++;
    }
    cout << maz << " " << miz;
}
