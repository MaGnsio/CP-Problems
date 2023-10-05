/**
 *    author:  MaGnsi0
 *    created: 25.07.2023 18:25:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<pair<int, int>>> groups(1);
        for (int i = 0; i < n; ++i) {
            groups[0].emplace_back(a[i], i + 1);
        }
        for (int b = k - 1; b >= 0; --b) {
            vector<vector<pair<int, int>>> new_groups;
            for (int i = 0; i < (int)groups.size(); ++i) {
                new_groups.push_back(vector<pair<int, int>>());
                for (int j = 0; j < (int)groups[i].size(); ++j) {
                    if ((groups[i][j].first >> b) & 1) {
                        new_groups.back().push_back(groups[i][j]);
                    }
                }
                new_groups.push_back(vector<pair<int, int>>());
                for (int j = 0; j < (int)groups[i].size(); ++j) {
                    if (!((groups[i][j].first >> b) & 1)) {
                        new_groups.back().push_back(groups[i][j]);
                    }
                }
            }
            bool works = false;
            for (int i = 0; i < (int)new_groups.size(); ++i) {
                works |= (int)new_groups[i].size() >= 2;
            }
            if (!works) { continue; }
            groups.clear();
            for (int i = 0; i < (int)new_groups.size(); ++i) {
                if ((int)new_groups[i].size() >= 2) {
                    groups.push_back(new_groups[i]);
                }
            }
        }
        assert((int)groups[0].size() >= 2);
        int X = 0, I = groups[0][0].second, J = groups[0][1].second;
        for (int b = 0; b < k; ++b) {
            if (a[I - 1] >> b & 1) { continue; }
            if (a[J - 1] >> b & 1) { continue; }
            X |= (1 << b);
        }
        cout << I << " " << J << " " << X << "\n";
    }
}
