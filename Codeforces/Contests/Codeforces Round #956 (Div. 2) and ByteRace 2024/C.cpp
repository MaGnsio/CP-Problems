/**
 *    author:  MaGnsi0
 *    created: 07.07.2024 17:51:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<vector<int64_t>> a(3, vector<int64_t>(n));
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 1; j < n; ++j) {
                a[i][j] += a[i][j - 1];
            }
        }
        int64_t sum = (a[0][n - 1] + 2) / 3;
        vector<int> I(3);
        iota(I.begin(), I.end(), 0);
        vector<pair<int, int>> ans(3, {-1, -1});
        do {
            for (int i = 0; i + 2 < n; ++i) {
                if (a[I[0]][i] < sum) { continue; }
                int low = i + 1, high = n - 2, j = -1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (a[I[1]][mid] - a[I[1]][i] >= sum) {
                        j = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
                if (j == -1) { continue; }
                if (a[I[2]][n - 1] - a[I[2]][j] < sum) { continue; }
                ans[I[0]] = {1, i + 1};
                ans[I[1]] = {i + 2, j + 1};
                ans[I[2]] = {j + 2, n};
            }
        } while (next_permutation(I.begin(), I.end()));
        if (ans[0].first == -1) {
            cout << -1;
        } else {
            for (auto [x, y] : ans) {
                cout << x << " " << y << " ";
            }
        }
        cout << "\n";
    }
}
