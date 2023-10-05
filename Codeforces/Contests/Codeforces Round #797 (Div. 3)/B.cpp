/**
 *    author:  MaGnsi0
 *    created: 07.06.2022 16:34:05
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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        bool can = true;
        set<int> non_zero, zero;
        for (int i = 0; i < n; ++i) {
            if (b[i] == 0) {
                zero.insert(a[i]);
            } else if (a[i] >= b[i]) {
                non_zero.insert(a[i] - b[i]);
            } else {
                can = false;
            }
        }
        if ((int)non_zero.size() > 1) {
            can = false;
        }
        if (!non_zero.empty() && !zero.empty() && *zero.rbegin() > *non_zero.begin()) {
            can = false;
        }
        cout << (can ? "YES" : "NO") << "\n";
    }
}
