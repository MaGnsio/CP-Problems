/**
 *    author:  MaGnsi0
 *    created: 18.09.2023 17:46:17
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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; a[i]--;
            b[i] = i;
        }
        sort(b.begin(), b.end(), [&](int i, int j) {
                return a[i] > a[j];
            });
        int min_j = n, max_j = -1;
        vector<int> x_low(k, n), y_low(k, n);
        vector<int> x_high(k, 0), y_high(k, 0);
        for (int i = 0; i < n; ++i) {
            int j = b[i];
            min_j = min(min_j, j);
            max_j = max(max_j, j);
            x_low[a[j]] = min(x_low[a[j]], min_j); 
            y_low[a[j]] = min(y_low[a[j]], min_j);
            x_high[a[j]] = max(x_high[a[j]], max_j); 
            y_high[a[j]] = max(y_high[a[j]], max_j);
        }
        for (int i = 0; i < k; ++i) {
            if (x_low[i] == n) {
                cout << 0 << " ";
            } else {
                cout << (x_high[i] - x_low[i] + 1) + (y_high[i] - y_low[i] + 1) << " ";
            }
        }
        cout << "\n";
    }
}
