/**
 *    author:  MaGnsi0
 *    created: 21.12.2024 19:53:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<set<int>> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i].insert(i + 1);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] == '1') {
                    ans[j].insert(ans[i].begin(), ans[i].end());
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << (int)ans[i].size();
            for (int x : ans[i]) {
                cout << " " << x;
            }
            cout << "\n";
        }
    }
}
