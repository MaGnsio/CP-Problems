//https://codeforces.com/problemset/problem/492/B
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7, d = 1e-10;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, l, x = 0;
    cin >> n >> l;
    vector<int> v(n);
    for (auto& x : v) cin >> x;
    sort (v.begin (), v.end ());
    for (int i = 1; i < n; ++i) x = max (x, v[i] - v[i - 1]);
    double ans = max ({x, 2 * v[0], 2 * (l - v[n - 1])}) / (double) 2;
    cout << fixed << setprecision (10) << ans;
}

