//https://atcoder.jp/contests/abc194/tasks/abc194_b
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7, MX = 10e5 + 1;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, ans = INT_MAX;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j) ans = min (ans, a[i] + b[j]);
            else ans = min (ans, max (a[i], b[j]));
        }
    }
    cout << ans;
}

