/**
 *    author:  MaGnsi0
 *    created: 25.07.2024 15:10:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, Q; cin >> n >> Q;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int64_t> sum(n);
    for (int i = 0; i < n; ++i) {
        sum[i] = (i ? sum[i - 1] : 0) + a[i];
    }
    while (Q--) {
        int64_t x; cin >> x;
        int64_t low = 0, high = n - 1, j = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (a[mid] < x) {
                j = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        int64_t take = (j == -1 ? n * x : sum[j] + (n - j - 1) * x);
        int64_t res = n * x - take;
        cout << 50LL * res << "\n";
    }
}
