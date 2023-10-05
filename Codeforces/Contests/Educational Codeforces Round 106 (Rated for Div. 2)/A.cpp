//https://codeforces.com/contest/1499/problem/A
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void solve ()
{
    int n, k1, k2, w, b;
    cin >> n >> k1 >> k2 >> w >> b;
    if (min (k1, k2) + (max (k1, k2) - min (k1, k2)) / 2 < w) cout << "NO\n";
    else if (min (n - k1, n - k2) + (max (n - k1, n - k2) - min (n - k1, n - k2)) / 2 < b) cout << "NO\n";
    else cout << "YES\n";
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--)
        solve ();
}

