//
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
    int n, m, x, y, cnt = 0;
    cin >> n >> m >> x >> y;
    vector<string> v (n);
    for (auto& s : v) cin >> s;
    if (v[x - 1][y - 1] == '#') return cout << 0, 0;
    for (int i = x - 1; i >= 0; --i, ++cnt) if (v[i][y - 1] == '#') break;
    for (int i = x; i < n; ++i, ++cnt) if (v[i][y - 1] == '#') break;
    for (int i = y - 2; i >= 0; --i, ++cnt) if (v[x - 1][i] == '#') break;
    for (int i = y; i < m; ++i, ++cnt) if (v[x - 1][i] == '#') break;
    cout << cnt;
}

