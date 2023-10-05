/**
 *    author:  MaGnsi0
 *    created: 19.05.2023 17:51:17
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
        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }
        int pos_max;
        if (a[0] == n) {
            for (int i = 0; i < n; ++i) {
                if (a[i] == n - 1) { pos_max = i; }
            }
        } else {
            for (int i = 0; i < n; ++i) {
                if (a[i] == n) { pos_max = i; }
            }
        }
        vector<int> ans(n);
        iota(ans.begin(), ans.end(), 1);
        for (int l = 0; l < pos_max; ++l) {
            vector<int> b(a.begin() + l, a.begin() + pos_max);
            reverse(b.begin(), b.end());
            vector<int> c;
            for (int i = pos_max; i < n; ++i) {
                c.push_back(a[i]);
            }
            c.insert(c.end(), b.begin(), b.end());
            for (int i = 0; i < l; ++i) {
                c.push_back(a[i]);
            }
            ans = max(ans, c);
        }
        if (n > 1) {
            vector<int> c;
            c.push_back(a[n - 1]);
            c.insert(c.end(), a.begin(), a.begin() + n - 1);
            ans = max(ans, c);
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
