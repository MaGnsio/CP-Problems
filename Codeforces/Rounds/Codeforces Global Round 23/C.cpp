/**
 *    author:  MaGnsi0
 *    created: 16.10.2022 23:22:15
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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        set<int> s;
        for (int i = 0; i < n; ++i) {
            s.insert(i + 1);
        }
        vector<int> ans(n, 1);
        for (int i = n - 1; i > 0; --i) {
            int diff = a[i - 1] - a[i];
            while (!s.empty() && diff > 0) {
                if (s.count(diff)) {
                    ans[diff - 1] = i + 1;
                    s.erase(diff);
                    diff -= diff;
                } else {
                    auto it = s.lower_bound(diff);
                    if (it == s.end()) {
                        auto it2 = s.rbegin();
                        ans[*it2 - 1] = i + 1;
                        diff -= *it2;
                        s.erase(*it2);
                    } else {
                        ans[*it - 1] = i + 1;
                        diff -= *it;
                        s.erase(it);
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
