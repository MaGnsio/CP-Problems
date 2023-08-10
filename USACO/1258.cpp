/**
 *    author:  MaGnsi0
 *    created: 07.08.2023 17:48:38
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    function<bool(int, int, int)> F = [&](int i, int k, int j) {
        if (k == -1) { return true; }
        return (k - i) * (h[j] - h[i]) >= (j - i) * (h[k] - h[i]);
    };
    int ans = 0;
    vector<set<int>> can_see(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int k = can_see[i].empty() ? -1 : *can_see[i].rbegin();
            if (F(i, k, j)) { can_see[i].insert(j); }
        }
        ans += (int)can_see[i].size();
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int x, y;
        cin >> x >> y;
        h[--x] += y;
        for (int j = 0; j < x; ++j) {
            auto it = can_see[j].lower_bound(x);
            bool added_x = false;
            if (it != can_see[j].end() && *it == x) {
                added_x = true;
            } else {
                int k = (it == can_see[j].begin() ? -1 : *(--it));
                if (F(j, k, x)) {
                    added_x = true; ans++;
                    can_see[j].insert(x);
                }
            }
            if (added_x) {
                while (can_see[j].upper_bound(x) != can_see[j].end()) {
                    int k = *can_see[j].upper_bound(x);
                    if (F(j, x, k)) { break; }
                    can_see[j].erase(k); ans--;
                }
            }
        }
        ans -= (int)can_see[x].size();
        can_see[x].clear();
        for (int j = x + 1; j < n; ++j) {
            int k = can_see[x].empty() ? -1 : *can_see[x].rbegin();
            if (F(x, k, j)) { can_see[x].insert(j); }
        }
        ans += (int)can_see[x].size();
        cout << ans << "\n";
    }
}
