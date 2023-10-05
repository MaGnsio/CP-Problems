/**
 *    author:  MaGnsi0
 *    created: 25.09.2023 04:56:09
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 2e18;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int64_t> b(n, OO);
    for (int i = 1; i < n; ++i) {
        b[i - 1] = a[i] - a[i - 1];
    }
    sort(b.begin(), b.end());
    for (int i = 1; i < n; ++i) {
        b[i] += b[i - 1];
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int64_t L, R;
        cin >> L >> R;
        int64_t X = R - L + 1, j = -1;
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (b[mid] - (mid ? b[mid - 1] : 0) <= X) {
                j = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << (j != -1 ? b[j] : 0) + X * (n - j - 1) << " ";
    }
}
