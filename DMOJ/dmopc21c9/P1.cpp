/**
 *    author:  MaGnsi0
 *    created: 10.04.2023 22:33:59
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> a(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i];
    }
    int64_t L = 1, R = a[0] - 1;
    for (int i = 1; i < n - 1; ++i) {
        int64_t L1 = a[i - 1] - R;
        int64_t R1 = a[i - 1] - L;
        int64_t L2 = 1, R2 = a[i] - 1;
        L = max(L1, L2);
        R = min(R1, R2);
        if (L > R) { break; }
    }
    cout << max(R - L + 1, int64_t(0));
}
