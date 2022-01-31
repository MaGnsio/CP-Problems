/**
 *    author:  MaGnsi0
 *    created: 30.12.2021 17:16:46
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
        int res = n - 1;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int cnt = 0;
                for (int k = 0; k < n; ++k) {
                    cnt += ((a[j] - a[i]) * (k - i) != (a[k] - a[i]) * (j - i));
                }
                res = min(res, cnt);
            }
        }
        cout << res << "\n";
    }
}
