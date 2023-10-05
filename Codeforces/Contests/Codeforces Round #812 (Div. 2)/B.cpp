/**
 *    author:  MaGnsi0
 *    created: 06.08.2022 16:33:58
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
        bool ok = true;
        for (int i = 1; i < n; ++i) {
            if (a[i] >= a[i - 1]) {
                continue;
            }
            for (int j = i; j < n; ++j) {
                if (a[j] <= a[j - 1]) {
                    continue;
                }
                ok = false;
                break;
            }
            break;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
