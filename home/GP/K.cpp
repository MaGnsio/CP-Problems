/**
 *    author:  MaGnsi0
 *    created: 23.11.2024 11:58:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int k; cin >> k;
    int p; cin >> p;
    int m; cin >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i]; a[i]--;
    }
    vector<int> last(k), f(k), ans(n);
    set<pair<int, int>> allowed;
    for (int i = 0; i < k; ++i) {
        allowed.emplace(f[i], i);
    }
    for (int i = 0; i < n; ++i) {
        if (i - p >= 0) {
            last[ans[i - p]]--;
            if (last[ans[i - p]] == 0) {
                allowed.emplace(f[ans[i - p]], ans[i - p]);
            }
        }
        if (allowed.empty()) {
            cout << "impossible";
            return 0;
        }
        int s = (i < m ? a[i] : allowed.begin() -> second);
        if (allowed.count({f[s], s}) == 0) {
            cout << "impossible";
            return 0;
        }
        allowed.erase({f[s], s}); f[s]++; last[s]++, ans[i] = s;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << " ";
    }
}
