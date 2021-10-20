//https://codeforces.com/contest/1494/problem/B
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void solve ()
{
    int n, u, r, d, l;
    cin >> n >> u >> r >> d >> l;
    for (int i = 0; i < 16; ++i)
    {
        int tu = u, tr = r, td = d, tl = l;
        if (i & 1) tu--, tl--;
        if (i & 2) tu--, tr--;
        if (i & 4) td--, tr--;
        if (i & 8) td--, tl--;
        int lower = min ({tu, tr, td, tl});
        int upper = max ({tu, tr, td, tl});
        if (lower >= 0 && upper <= n - 2)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--)
        solve ();
}

