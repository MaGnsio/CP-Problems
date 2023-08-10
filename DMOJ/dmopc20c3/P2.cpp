/**
 *    author:  MaGnsi0
 *    created: 14.04.2023 22:36:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int j = 1; j < n; ++j) {
        vector<int> I(m);
        iota(I.begin(), I.end(), 0);
        sort(I.begin(), I.end(), [&](int x, int y) {
                return a[x][j] < a[y][j];
            });
        for (int i = 0; i < m; ++i) {
            int low = 0, high = i - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (a[I[i]][j] - a[I[mid]][j] == k) {
                    ans += a[I[i]][j - 1] - a[I[mid]][j - 1] == k;
                    break;
                } else if (a[I[i]][j] - a[I[mid]][j] > k) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
    }
    cout << ans << "\n";
}
