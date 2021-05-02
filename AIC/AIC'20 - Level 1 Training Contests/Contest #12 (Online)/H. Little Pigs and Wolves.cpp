//https://codeforces.com/group/aDFQm4ed6d/contest/279956/problem/H
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
    int n, m, cnt = 0;
    char a[12][12];
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] != 'P') continue;
            if (a[i - 1][j] == 'W') cnt++, a[i - 1][j] = 'X';
            else if (a[i][j - 1] == 'W') cnt++, a[i][j - 1] = 'X';
            else if (a[i][j + 1] == 'W') cnt++, a[i][j + 1] = 'X';
            else if (a[i + 1][j] == 'W') cnt++, a[i + 1][j] = 'X';
        }
    }
    cout << cnt;
}
