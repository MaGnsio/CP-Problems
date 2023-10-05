/**
 *    author:  MaGnsi0
 *    created: 25.07.2023 17:47:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (a[0] == a[n - 1]) {
            cout << (count(a.begin(), a.end(), a[0]) >= k ? "YES" : "NO") << "\n";
            continue;
        }
        bool ok = false;
        int color = a[0], cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == color) { cnt++; }
            if (cnt == k) {
                if (color == a[0]) {
                    color = a[n - 1];
                    cnt = 0;
                } else {
                    ok = true;
                    break;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
