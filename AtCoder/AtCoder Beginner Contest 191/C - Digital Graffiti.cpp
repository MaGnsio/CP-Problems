//https://atcoder.jp/contests/abc191/tasks/abc191_c
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
    int n, m, ans = 0;
    cin >> n >> m;
    char a[n][m];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    }
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < m - 1; ++j)
        {
            int cnt = (a[i][j] == '#') + (a[i][j + 1] == '#') + (a[i + 1][j] == '#') + (a[i + 1][j + 1] == '#');
            ans += (cnt & 1);
        }
    }
    cout << ans;
}

