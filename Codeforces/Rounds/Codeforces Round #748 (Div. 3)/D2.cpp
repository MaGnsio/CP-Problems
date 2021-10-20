/**
 *    author:  MaGnsi0
 *    created: 13.10.2021 16:27:24
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> cnt_i(n, 0);
        for (int i = 0; i < n; ++i) {
            int j = i, cnt = 0;
            while (a[j] == a[i] && j < n) {
                cnt++;
                j++;
            }
            cnt_i[i] = cnt;
            j--;
        }
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            if (cnt_i[i] >= n / 2) {
                ok = true;
            }
        }
        if (ok) {
            cout << "-1\n";
            continue;
        }
        int res = 0;
        for (int i = 0; i <= n / 2; ++i) {
            vector<int> cnt(N, 0);
            for (int j = i + 1; j < n; ++j) {
                int x = abs(a[j] - a[i]);
                if (!x) {
                    continue;
                }
                for (int k = 1; k * k <= x; ++k) {
                    if (x % k == 0) {
                        cnt[k]++;
                        if (k * k != x) {
                            cnt[x / k]++;
                        }
                    }
                }
            }
            for (int j = 1; j < N; ++j) {
                if (cnt[j] + cnt_i[i] >= n / 2) {
                    res = max(res, j);
                }
            }
        }
        cout << res << "\n";
    }
}
