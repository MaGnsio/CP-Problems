/**
 *    author:  MaGnsi0
 *    created: 27.09.2024 17:01:38
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int>> pos(n + 1);
        for (int i = 0; i < n; ++i) {
            pos[a[i]].push_back(i);
        }
        int L = n, R = -1;
        vector<int> bad(n + 1);
        for (int x = 1; x <= n; ++x) {
            for (int j : pos[x]) {
                L = min(L, j);
                R = max(R, j);
            }
            if (pos[x].empty()) { continue; }
            {
                int k = pos[x].back();
                int low = 0, high = k - 1, j = -1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (k - mid + 1 + max(0, mid - L) > a[k]) {
                        j = mid; low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                bad[0]++; bad[j + 1]--;
            }
            {
                int k = pos[x][0];
                int low = k + 1, high = n - 1, j = n;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (mid - k + 1 + max(0, R - mid) > a[k]) {
                        j = mid; high = mid - 1;
                    } else {
                         low = mid + 1;
                    }
                }
                bad[j]++; bad[n]--;
            }
        }
        for (int i = 1; i <= n; ++i) {
            bad[i] += bad[i - 1];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += bad[i] == 0;
        }
        cout << ans << "\n";
    }
}
