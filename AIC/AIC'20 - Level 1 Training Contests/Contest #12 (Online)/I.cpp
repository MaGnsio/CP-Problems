//https://codeforces.com/group/aDFQm4ed6d/contest/279956/problem/I
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m;
    cin >> n >> m;
    unordered_set<int> s;
    for (int i = 1; i <= n; ++i) s.insert (i);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        if (s.count (x)) s.erase (x);
        if (s.count (y)) s.erase (y);
    }
    int x = *s.begin ();
    cout << n - 1 << "\n";
    for (int i = 1; i <= n; ++i)
    {
        if (i == x) continue;
        cout << i << " " << x << "\n";
    }
}

