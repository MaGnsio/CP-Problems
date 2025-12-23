/**
 *    author:  MaGnsi0
 *    created: 23.12.2025 16:53:34
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
            cin >> a[i];
        }
        function<int(int)> V = [&](int j) {
            int r1 = j ? abs(a[j] - a[j - 1]) : 0;
            int r2 = j + 1 < n ? abs(a[j] - a[j + 1]) : 0;
            int a1 = j && j + 1 < n ? abs(a[j + 1] - a[j - 1]) : 0;
            return a1 - r1 - r2;
        };
        int sum = 0, x = INT_MAX;
        for (int i = 0; i < n; ++i) {
            x = min(x, V(i));
        }
        for (int i = 1; i < n; ++i) {
            sum += abs(a[i] - a[i - 1]);
        }
        cout << sum + x << "\n";
    }
}
