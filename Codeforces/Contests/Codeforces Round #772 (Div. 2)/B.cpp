/**
 *    author:  MaGnsi0
 *    created: 20.02.2022 16:26:24
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
        int res = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                if (i + 2 < n) {
                    a[i + 1] = max(a[i], a[i + 2]);
                } else {
                    a[i + 1] = a[i];
                }
                res++;
            }
        }
        cout << res << "\n";
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}
