/**
 *    author:  MaGnsi0
 *    created: 22.10.2022 05:05:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int B;
    cin >> B;
    vector<int> sz(5);
    vector<vector<pair<int64_t, string>>> a(5);
    for (int i = 0; i < 5; ++i) {
        cin >> sz[i];
        a[i].resize(sz[i]);
        for (int j = 0; j < sz[i]; ++j) {
            cin >> a[i][j].second >> a[i][j].first;
        }
        sort(a[i].begin(), a[i].end());
    }
    int64_t ans = -1;
    vector<string> res(5, "");
    for (int i = 0; i < sz[1]; ++i) {
        for (int j = 0; j < sz[2]; ++j) {
            for (int k = 0; k < sz[3]; ++k) {
                for (int l = 0; l < sz[4]; ++l) {
                    int64_t sum = a[1][i].first + a[2][j].first + a[3][k].first + a[4][l].first;
                    if (sum > B) {
                        continue;
                    }
                    int L = 0, R = sz[0] - 1, m = -1;
                    while (L <= R) {
                        int mid = (L + R) / 2;
                        if (a[0][mid].first <= B - sum) {
                            m = mid;
                            L = mid + 1;
                        } else {
                            R = mid - 1;
                        }
                    }
                    if (m == -1) {
                        continue;
                    }
                    vector<string> names = {a[0][m].second, a[1][i].second, a[2][j].second, a[3][k].second, a[4][l].second};
                    if (sum + a[0][m].first > ans) {
                        ans = sum + a[0][m].first;
                        res = names;
                    } else if (sum + a[0][m].first == ans) {
                        res = min(res, names);
                    }
                }
            }
        }
    }
}
