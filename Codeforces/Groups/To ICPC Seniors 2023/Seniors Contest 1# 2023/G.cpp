/**
 *    author:  MaGnsi0
 *    created: 04.02.2023 09:40:38
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
        vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        bool ok = false;
        for (int i = 0, j = 0; i < n; ++i) {
            if (a[i] == b[j]) {
                j++;
            }
            if (j == m) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        multiset<int> s(a.begin(), a.end());
        for (int i = 0; i < m; ++i) {
            s.erase(s.find(b[i]));
        }
        sort(a.begin(), a.end());
        int j = 0;
        while (!s.empty()) {
            auto it = s.begin();
            if (*it != a[j]) {
                ok = false;
                break;
            }
            s.erase(it);
            j++;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
