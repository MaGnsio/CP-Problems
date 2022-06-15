/**
 *    author:  MaGnsi0
 *    created: 31.03.2022 20:56:24
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cnt0 += a[i][j] == '0';
                cnt1 += a[i][j] == '1';
            }
        }
        vector<int> diagonal;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j]) {
                    continue;
                }
                int cnt = 0;
                for (int k = 0; k < n; ++k) {
                    cnt += a[(i + k) % n][(j + k) % n] == '1';
                    visited[(i + k) % n][(j + k) % n] = true;
                }
                diagonal.push_back(cnt);
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < (int)diagonal.size(); ++i) {
            ans = min(ans, (n - diagonal[i]) + (cnt1 - diagonal[i]));
        }
        cout << ans << "\n";
    }
}
