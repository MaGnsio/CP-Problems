/**
 *    author:  MaGnsi0
 *    created: 07.06.2022 16:34:06
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
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        c[0] = b[0] - a[0];
        for (int i = 1; i < n; ++i) {
            c[i] = b[i] - max(a[i], b[i - 1]);
        }
        for (int i = 0; i < n; ++i) {
            cout << c[i] << " ";
        }
        cout << "\n";
    }
}
