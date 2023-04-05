/**
 *    author:  MaGnsi0
 *    created: 27.01.2023 20:23:00
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
        vector<vector<int>> a(n, vector<int>(n - 1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                cin >> a[i][j];
                a[i][j]--;
            }
        }
        vector<set<int>> b(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                b[a[i][j]].insert(a[i][j - 1]);
                if (j > 1) {
                    b[a[i][j]].insert(a[i][j - 2]);
                }
            }
        }
        vector<int> ans;
        vector<bool> done(n, false);
        for (int i = 0; i < n; ++i) {
            int x = -1;
            for (int j = 0; j < n; ++j) {
                if (!done[j] && b[j].empty()) {
                    x = j;
                    break;
                }
            }
            assert(x != -1);
            for (int j = 0; j < n; ++j) {
                b[j].erase(x);
            }
            done[x] = true;
            ans.push_back(x + 1);
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
