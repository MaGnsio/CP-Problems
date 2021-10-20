//https://codeforces.com/group/aDFQm4ed6d/contest/286323/problem/J
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
    int l[4], s[4], r[4], p[4];
    for (int i = 0; i < 4; ++i) cin >> l[i] >> s[i] >> r[i] >> p[i];
    for (int i = 0; i < 4; ++i)
    {
        if (!p[i]) continue;
        int x = l[i] + s[i] + r[i];
        int y = l[(i + 1) % 4] + s[(i + 2) % 4] + r[(i + 3) % 4];
        if (x || y) return cout << "YES", 0;
    }
    cout << "NO";
}
