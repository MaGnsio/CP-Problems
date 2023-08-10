/**
 *    author:  MaGnsi0
 *    created: 27.07.2023 06:34:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int64_t> p(n), s(n);
        p[0] = a[0], s[n - 1] = a[n - 1];
        for (int i = 1; i < n; ++i) {
            p[i] = a[i] + p[i - 1];
        }
        for (int i = n - 2; i >= 0; --i) {
            s[i] = a[i] + s[i + 1];
        }
        for (int i = 0; i < m; ++i) {
            int64_t time; cin >> time;
            int L = 0, R = -1;
            {
                int low = 0, high = n - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (p[mid] > time) {
                        L = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
            {
                int low = 0, high = n - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (s[mid] > time) {
                        R = mid;
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
            }
            cout << max(R - L + 1, 0) << "\n";
        }
    }
}
