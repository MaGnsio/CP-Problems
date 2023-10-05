/**
 *    author:  MaGnsi0
 *    created: 21.01.2023 17:08:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<vector<int>> b(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j * j <= a[i]; ++j) {
                if (a[i] % j) { continue; }
                if (j <= m) { b[i].push_back(j); }
                if (a[i] / j != j && a[i] / j <= m) { b[i].push_back(a[i] / j); }
            }
        }
        int low = 0, high = a[n - 1] - a[0], ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            set<int> s;
            vector<int> cnt(m + 1, 0);
            for (int i = 1; i <= m; ++i) {
                s.insert(i);
            }
            int cur_l = 0;
            for (int i = 0; i < (int)b[cur_l].size(); ++i) {
                cnt[b[cur_l][i]]++;
                s.erase(b[cur_l][i]);
            }
            bool ok = s.empty();
            for (int i = 1; i < n; ++i) {
                while (a[i] - a[cur_l] > mid) {
                    for (int j = 0; j < (int)b[cur_l].size(); ++j) {
                        cnt[b[cur_l][j]]--;
                        if (cnt[b[cur_l][j]] == 0) {
                            s.insert(b[cur_l][j]);
                        }
                    }
                    cur_l++;
                }
                for (int j = 0; j < (int)b[i].size(); ++j) {
                    cnt[b[i][j]]++;
                    s.erase(b[i][j]);
                }
                ok = ok || s.empty();
            }
            if (ok) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}
