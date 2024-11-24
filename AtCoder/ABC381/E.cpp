/**
 *    author:  MaGnsi0
 *    created: 24.11.2024 21:58:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int Q; cin >> Q;
    string s; cin >> s;
    for (auto& c : s) { c = (c == '/' ? '0' : c); }
    vector f(3, vector<int>(n, 0));
    for (int j = 0; j < n; ++j) {
        f[s[j] - '0'][j]++;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 1; j < n; ++j) {
            f[i][j] += f[i][j - 1];
        }
    }
    function<int(int, int, int)> get = [&](int i, int c, int s) {
        int need = c + (s ? f[i][s - 1] : 0);
        int low = s, high = n - 1, j = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (f[i][mid] >= need) {
                j = mid; high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return j;
    };
    function<bool(int, int, int)> F = [&](int x, int l, int r) {
        int j1 = (x ? get(1, x, l) : l - 1);
        if (j1 > r) { return false; }
        int j2 = get(0, 1, j1 + 1);
        if (j2 > r) { return false; }
        int j3 = (x ? get(2, x, j2 + 1) : j2);
        if (j3 > r) { return false; }
        return true;
    };
    while (Q--) {
        int l; cin >> l; l--;
        int r; cin >> r; r--;
        int low = 0, high = r - l + 1, ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (F(mid, l, r)) {
                ans = 2 * mid + 1;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }
}
