/**
 *    author:  MaGnsi0
 *    created: 26.08.2023 17:41:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        if (k & 1) {
            vector<string> ans(2, "");
            for (int i = 0; i < n; ++i) {
                ans[i % 2] += s[i];
            }
            sort(ans[0].begin(), ans[0].end());
            sort(ans[1].begin(), ans[1].end());
            for (int i = 0; i < (int)ans[0].size(); ++i) {
                cout << ans[0][i];
                if (i < ans[1].size()) {
                    cout << ans[1][i];
                }
            }
            cout << "\n";
        } else {
            sort(s.begin(), s.end());
            cout << s << "\n";
        }
    }
}
