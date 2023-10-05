/**
 *    author:  MaGnsi0
 *    created: 01.02.2023 05:22:04
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
        int64_t x, y;
        cin >> x >> y;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int64_t> b(n), c(n);
        b[0] = a[0], c[0] = b[0] + 1;
        for (int i = 1; i < n; ++i) {
            b[i] = (c[i - 1] >= a[i] ? b[i - 1] : a[i] - i);
            c[i] = (c[i - 1] >= a[i] ? c[i - 1] : a[i]) + 1;
        }
        int64_t matches = 0;
        while (true) {
            int k = upper_bound(b.begin(), b.end(), x) - b.begin();
            int wins = k, loses = n - k;
            if (x + wins >= y || wins == n) {
                cout << matches + y - x << "\n";
                break;
            }
            if (wins <= loses) {
                cout << -1 << "\n";
                break;
            }
            int64_t need = (b[k] - x + wins - loses - 1) / (wins - loses);
            need = min(need, (y - x - loses - 1) / (wins - loses));
            x += need * (wins - loses);
            matches += n * need;
        }
    }
}
