/**
 *    author:  MaGnsi0
 *    created: 30.05.2024 17:52:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        vector<int64_t> a(n + m + 1);
        vector<int64_t> b(n + m + 1);
        for (int i = 0; i <= n + m; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i <= n + m; ++i) {
            cin >> b[i];
        }
        vector<int64_t> p(n + m + 1), sump1(n + m + 1), sump2(n + m + 1);
        vector<int64_t> t(n + m + 1), sumt1(n + m + 1), sumt2(n + m + 1);
        for (int i = 0; i <= n + m; ++i) {
            sump1[i] = a[i];
            sumt1[i] = b[i];
            if (a[i] > b[i]) {
                p[i] = 1;
                sump2[i] = a[i] - b[i];
            } else {
                t[i] = 1;
                sumt2[i] = b[i] - a[i];
            }
        }
        for (int i = 1; i <= n + m; ++i) {
            p[i] += p[i - 1], t[i] += t[i - 1];
            sump1[i] += sump1[i - 1], sumt1[i] += sumt1[i - 1];
            sump2[i] += sump2[i - 1], sumt2[i] += sumt2[i - 1];
        }
        if (n == 0) {
            for (int i = 0; i <= n + m; ++i) {
                cout << sumt1[n + m] - b[i] << " ";
            }
            cout << "\n";
            continue;
        }
        if (m == 0) {
            for (int i = 0; i <= n + m; ++i) {
                cout << sump1[n + m] - a[i] << " ";
            }
            cout << "\n";
            continue;
        }
        for (int i = 0; i <= n + m; ++i) {
            int64_t pi = p[i] - (i ? p[i - 1] : 0);
            int64_t ti = t[i] - (i ? t[i - 1] : 0);
            int64_t low = 0, high = n + m, j = -1;
            int si1 = (i ? p[i - 1] : -1);
            int si2 = (i ? t[i - 1] : -1);
            if (i == 0) {
                low++;
            } else if (i == n + m) {
                high--;
            } else if (si1 >= n || si2 >= m) {
                high = i - 1;
            } else {
                low = i + 1;
            }
            while (low <= high) {
                int mid = (low + high) / 2;
                int s1 = p[mid] - (mid >= i ? pi : 0);
                int s2 = t[mid] - (mid >= i ? ti : 0);
                if (s1 >= n || s2 >= m) {
                    j = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            int64_t s1 = p[j] - (j >= i ? pi : 0);
            int64_t s2 = t[j] - (j >= i ? ti : 0);
            if (s1 == n) {
                int64_t sump = sump2[j];
                int64_t sumt = sumt1[n + m] - b[i];
                if (j >= i && pi) {
                    sump -= (a[i] - b[i]);
                }
                cout << sump + sumt << " ";
            } else {
                int64_t sump = sump1[n + m] - a[i];
                int64_t sumt = sumt2[j];
                if (j >= i && ti) {
                    sumt -= (b[i] - a[i]);
                }
                cout << sump + sumt << " ";
            }
        }
        cout << "\n";
    }
}
