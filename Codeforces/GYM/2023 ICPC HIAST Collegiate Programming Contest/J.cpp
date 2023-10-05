/**
 *    author:  MaGnsi0
 *    created: 27.08.2023 15:51:54
**/
#include <bits/stdc++.h>

using namespace std;

bool test(int64_t median, int64_t add, vector<int64_t> a) {
    a.push_back(add);
    sort(a.begin(), a.end());
    int64_t n = (int)a.size();
    int64_t sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    if (median != a[(n + 1) / 2 - 1]) { return false; }
    if (sum != n * median) { return false; } //won't happen
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int64_t sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
        }
        int64_t ans = INT64_MAX;
        if (sum % n == 0) {
            int64_t x = sum / n;
            if (test(x, x, a)) {
                ans = min(ans, x);
            }
        }
        int j = (n + 1) / 2 - 1;
        if (test(a[j], a[j] * (n + 1) - sum, a)) {
            ans = min(ans, a[j] * (n + 1) - sum);
        }
        if (j && test(a[j - 1], a[j - 1] * (n + 1) - sum, a)) {
            ans = min(ans, a[j - 1] * (n + 1) - sum);
        }
        if (j + 1 < n && test(a[j + 1], a[j + 1] * (n + 1) - sum, a)) {
            ans = min(ans, a[j + 1] * (n + 1) - sum);
        }
        cout << ans << "\n";
    }
}
