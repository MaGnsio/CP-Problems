/**
 *    author:  MaGnsi0
 *    created: 27.02.2025 16:56:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        string s; cin >> s;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        {
            int i = 0, j = n - 1;
            while (i <= j && s[i] == 'R') { i++; }
            while (i <= j && s[j] == 'R') { j--; }
            if (i > j) {
                cout << 0 << "\n";
                continue;
            }
            s = s.substr(i, j - i + 1);
            a = vector<int>(a.begin() + i, a.begin() + j + 1);
            n = (int)a.size();
        }
        vector<int> blocks; blocks.push_back(a[0]);
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) {
                blocks.back() = max(blocks.back(), a[i]);
            } else {
                blocks.push_back(a[i]);
            }
        }
        int m = (int)blocks.size();
        int need = (m + 1) / 2;
        if (m == 1) {
            cout << (k ? 0 : blocks[0]) << "\n";
            continue;
        }
        if (need <= k) {
            cout << 0 << "\n";
            continue;
        }
        function<bool(int)> F = [&](int x) {
            int turns = k;
            for (int i = 0; i < m; /*_*/) {
                if (blocks[i] <= x) { i += 2; continue; }
                int j = i;
                while (j + 1 < m && blocks[j + 1] <= x) {
                    j += 2;
                }
                turns--; i = j + 2;
            }
            return turns >= 0;
        };
        int low = 0, high = 1e9, ans = 1e9;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (F(mid)) {
                ans = mid; high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}
