/**
 *    author:  MaGnsi0
 *    created: 08.10.2024 20:43:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (count(a.begin(), a.end(), k) == 0) {
            cout << "NO\n";
            continue;
        }
        if (n == 1) {
            cout << (a[0] == k ? "YES" : "NO") << "\n";
            continue;
        }
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            vector<int> b = { a[i] };
            for (int j = i + 1; j <= i + 2 && j < n; ++j) {
                b.push_back(a[j]);
                sort(b.begin(), b.end());
                int m = (int)b.size();
                ok |= b[(m - 1) / 2] >= k;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
