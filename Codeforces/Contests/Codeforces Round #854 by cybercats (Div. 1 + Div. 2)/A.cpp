/**
 *    author:  MaGnsi0
 *    created: 27.02.2023 16:37:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }
        int last = n - 1;
        set<int> s;
        vector<int> ans(n, -1);
        for (int i = 0; i < m; ++i) {
            if (s.count(a[i])) { continue; }
            s.insert(a[i]);
            if (last >= 0) {
                ans[last--] = i + 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
