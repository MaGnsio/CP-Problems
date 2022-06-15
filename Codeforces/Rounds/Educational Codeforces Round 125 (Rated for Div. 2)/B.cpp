/**
 *    author:  MaGnsi0
 *    created: 22.03.2022 16:38:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, b, x, y;
        cin >> n >> b >> x >> y;
        vector<int> a(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            if (a[i - 1] + x <= b) {
                a[i] = a[i - 1] + x;
            } else {
                a[i] = a[i - 1] - y;
            }
        }
        cout << accumulate(a.begin(), a.end(), 0LL) << "\n";
    }
}
