/**
 *    author:  MaGnsi0
 *    created: 10.01.2023 18:32:29
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
        vector<int> c(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            if (a[i] <= b[i]) { continue; }
            c[b[i]]++, c[a[i]]--;
        }
        for (int i = 1; i <= n + 1; ++i) {
            c[i] += c[i - 1];
        }
        vector<bool> ok(n + 1, true);
        for (int i = n; i > 0; --i) {
            if (c[i]) { ok[i] = false; }
            for (int j = 2 * i; j <= n; j += i) {
                ok[i] = ok[i] & ok[j];
            }
        }
        int cnt = count(ok.begin() + 1, ok.end(), true);
        cout << cnt << "\n";
        for (int i = 1; i <= n; ++i) {
            if (ok[i]) {
                cout << i << " ";
            }
        }
        cout << "\n";
    }
}
