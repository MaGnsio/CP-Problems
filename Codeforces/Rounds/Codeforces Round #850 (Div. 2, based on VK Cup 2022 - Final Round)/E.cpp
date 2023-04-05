/**
 *    author:  MaGnsi0
 *    created: 05.02.2023 15:42:20
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
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = n;
            cin >> a[i];
        }
        vector<int64_t> b = a;
        sort(b.begin(), b.end());
        vector<int64_t> stair;
        for (int i = 0; i < n; ++i) {
            if (b[i] >= stair.size() + 1) {
                stair.push_back(b[i]);
            }
        }
        int m = (int)stair.size();
        vector<int> all(n + 1, 0), in_stair_size(n + 1, 0);
        vector<vector<int>> in_stair(n + 1);
        for (int i = 0; i < n; ++i) {
            all[a[i]]++;
        }
        for (int i = m - 1; i >= 0; --i) {
            in_stair[stair[i]].push_back(i);
            in_stair_size[stair[i]]++;
        }
        set<int> s;
        for (int i = 1; i <= n; ++i) {
            if (all[i] > in_stair_size[i]) {
                s.insert(i);
            }
        }
        int64_t cur_stair_size = m, cur_sum = accumulate(stair.begin(), stair.end(), int64_t(0));
        vector<int64_t> ans(n);
        ans[n - 1] = cur_sum - cur_stair_size * (cur_stair_size + 1) / 2;
        for (int i = n - 2; i >= 0; --i) {
            all[a[i + 1]]--;
            if (all[a[i + 1]] == in_stair_size[a[i + 1]]) {
                s.erase(a[i + 1]);
            }
            if (all[a[i + 1]] < in_stair_size[a[i + 1]]) {
                int j = in_stair[a[i + 1]].back();
                in_stair[a[i + 1]].pop_back();
                in_stair_size[a[i + 1]]--;
                auto it = s.lower_bound(j + 1);
                if (it == s.end()) {
                    cur_sum -= a[i + 1];
                    cur_stair_size--;
                } else {
                    cur_sum -= a[i + 1];
                    cur_sum += *it;
                    in_stair[*it].push_back(j);
                    in_stair_size[*it]++;
                    if (all[*it] == in_stair_size[*it]) {
                        s.erase(it);
                    }
                }
            }
            ans[i] = cur_sum - cur_stair_size * (cur_stair_size + 1) / 2;
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
