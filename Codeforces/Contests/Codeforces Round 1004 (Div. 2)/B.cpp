/**
 *    author:  MaGnsi0
 *    created: 11.02.2025 16:42:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; a[i]--;
        }
        sort(a.begin(), a.end());
        vector<int> b1, b2;
        for (int i = 0; i < n; i += 2) {
            b1.push_back(a[i]);
            b2.push_back(a[i + 1]);
        }
        bool ok = true;
        vector<bool> in_bag(n + 1, false);
        for (int i = 0; i < n / 2; ++i) {
            if (b1[i] == b2[i]) {
                if (i && b1[i] <= b1[i - 1]) { b1[i] = b2[i] = b1[i - 1] + 1; }
                in_bag[b1[i]] = true;
                continue;
            } else {
                bool all_there = true;
                for (int j = b1[i]; j < b2[i]; ++j) {
                    all_there = all_there && in_bag[j];
                }
                if (all_there) {
                    b1[i] = b2[i];
                    if (i && b1[i] <= b1[i - 1]) { b1[i] = b2[i] = b1[i - 1] + 1; }
                    in_bag[b1[i]] = true;
                } else {
                    ok = false;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
