//https://vjudge.net/contest/416254#problem/K
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
    ll r, d, n, cnt = 0;
    cin >> r >> d >> n;
    while (n--)
    {
        ll xi, yi, ri;
        cin >> xi >> yi >> ri;
        if ((xi * xi) + (yi * yi) >= (r - d + ri) * (r - d + ri) && (xi * xi) + (yi * yi) <= (r - ri) * (r - ri)) cnt++;
    }
    cout << cnt;
}

