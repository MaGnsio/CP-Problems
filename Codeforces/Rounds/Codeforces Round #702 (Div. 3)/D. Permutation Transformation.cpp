//https://codeforces.com/contest/1490/problem/D
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void build (int l, int r, vector<int> &v, vector<int> &d, int curd = 0)
{
    if (r < l) return;
    if (l == r)
    {
        d[l] = curd;
        return;
    }
    int m = l;
    for (int i = l + 1; i <= r; ++i) if (v[i] > v[m]) m = i;
    d[m] = curd;
    build (l, m - 1, v, d, curd + 1);
    build (m + 1, r, v, d, curd + 1);
}

void solve ()
{
    int n;
    cin >> n;
    vector<int> v(n), d(n);
    for (auto& x : v) cin >> x;
    build (0, n - 1, v, d);
    for (auto& x : d) cout << x << " ";
    cout << "\n";
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--)
        solve ();
}

