/**
 *    author:  MaGnsi0
 *    created: 24.11.2023 16:53:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int64_t x = a[0], y = a[n - 1];
        vector<int64_t> ans;
        while (x != y) {
            if ((x & 1) == (y & 1)) {
                x /= 2, y /= 2;
                ans.push_back(0);
            } else if (x & 1) {
                x = (x + 1) / 2, y = (y + 1) / 2;
                ans.push_back(1);
            } else {
                x /= 2, y /= 2;
                ans.push_back(0);
            }
        }
        cout << (int)ans.size() << "\n";
        if ((int)ans.size() <= n) {
            for (int64_t x : ans) {
                cout << x << " ";
            }
            cout << "\n";
        }
    }
}
