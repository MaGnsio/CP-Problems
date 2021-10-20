//https://codeforces.com/group/nVgev28wQI/contest/303358/problem/N
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    freopen ("stickers.in", "r", stdin);
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> v(n + 2, vector<int> (m + 2, 0));
    for (int i = 0; i < k; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) swap (x1, x2);
        if (y1 > y2) swap (y1, y2);
        v[x1][y1]++;
        v[x1][y2 + 1]--;
        v[x2 + 1][y1]--;
        v[x2 + 1][y2 + 1]++;
    }
    for (int i = 1; i <= n + 1; ++i) {
        for (int j = 1; j <= m + 1; ++j) {
            v[i][j] += v[i][j - 1];
        }
    }
    for (int i = 1; i <= m + 1; ++i) {
        for (int j = 1; j <= n + 1; ++j) {
            v[j][i] += v[j - 1][i];
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) if (!v[i][j]) {
                cnt++;
        }
    }
    cout << cnt;
}

