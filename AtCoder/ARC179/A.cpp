/**
 *    author:  MaGnsi0
 *    created: 02.06.2024 15:01:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int64_t k; cin >> k;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (k > 0) {
        sort(a.begin(), a.end());
    } else {
        sort(a.begin(), a.end(), [](int64_t x, int64_t y) {
                if (x < 0 && y < 0) {
                    return x < y;
                }
                return x > y;
            });
    }
    vector<int64_t> b(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        b[i] = a[i - 1] + b[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        if ((b[i] >= k) && (b[i + 1] < k)) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
}
