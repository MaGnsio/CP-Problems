/**
 *    author:  MaGnsi0
 *    created: 25.05.2023 18:03:51
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
        string s;
        cin >> s;
        if (n & 1) {
            cout << -1 << "\n";
            continue;
        }
        vector<set<int>> a(2);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                a[0].insert(i);
            } else {
                a[1].insert(i);
            }
        }
        bool ok = true;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i) {
            if (ans[i]) { continue; }
            if (s[i] == '(') {
                if (a[1].empty()) {
                    ok = false;
                    break;
                }
                int j = *a[1].begin();
                ans[i] = ans[j] = 1;
                a[0].erase(i);
                a[1].erase(j);
            } else {
                if (a[0].empty()) {
                    ok = false;
                    break;
                }
                int j = *a[0].begin();
                ans[i] = ans[j] = 2;
                a[0].erase(j);
                a[1].erase(i);
            }
        }
        if (ok == false) {
            cout << -1 << "\n";
            continue;
        }
        int m = (count(ans.begin(), ans.end(), 1) != 0) + (count(ans.begin(), ans.end(), 2) != 0);
        if (m == 1) {
            ans = vector<int>(n, 1);
        }
        cout << m << "\n";
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
