//https://codeforces.com/contest/1490/problem/A
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void solve ()
{
    int n, cnt = 0;
    cin >> n;
    int a[n];
    for (auto& x : a) cin >> x;
    for (int i = 0; i < n - 1; ++i)
    {
        int mi = min (a[i], a[i + 1]), ma = max (a[i], a[i + 1]);
        while (2 * mi < ma) mi *= 2, cnt++;
    }
    cout << cnt << "\n";
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--)
        solve ();
}

