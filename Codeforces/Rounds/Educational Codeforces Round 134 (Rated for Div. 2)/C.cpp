/**
 *    author:  MaGnsi0
 *    created: 20.03.2023 07:32:51
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
        vector<int64_t> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        vector<int64_t> ans_min(n), ans_max(n);
        for (int i = 0; i < n; ++i) {
            assert(a[i] <= b[i]);
            ans_min[i] = *lower_bound(b.begin(), b.end(), a[i]) - a[i];
        }
        vector<int> can_push(n, 0);
        for (int i = n - 1; i > 0; --i) {
            can_push[i] = a[i] <= b[i - 1];
        }
        for (int i = 1; i < n; ++i) {
            can_push[i] += can_push[i - 1];
        }
        for (int i = 0; i < n; ++i) {
            int low = i + 1, high = n - 1, j = i;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (can_push[mid] - can_push[i] == mid - i) {
                    j = mid, low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            ans_max[i] = b[j] - a[i];
        }
        for (int i = 0; i < n; ++i) {
            cout << ans_min[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; ++i) {
            cout << ans_max[i] << " ";
        }
        cout << "\n";
    }
}
