/**
 *    author:  MaGnsi0
 *    created: 27.02.2023 16:44:40
**/
#include <bits/stdc++.h>

using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    function<int64_t(int64_t, int64_t)> random = [&](int64_t x, int64_t y) {
        return uniform_int_distribution<int64_t>(x, y)(rng);
    };
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), I(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        iota(I.begin(), I.end(), 0);
        sort(I.begin(), I.end(), [&](int i, int j) {
                return a[i] < a[j];
            });
        if (a[I[0]] == 1) {
            cout << (a[I[n - 1]] == 1 ? 0 : -1) << "\n";
            continue;
        }
        if (a[I[0]] == 2) {
            vector<int> b, c;
            for (int i = 1; i < n; ++i) {
                int j = I[0], k = I[i];
                while (a[k] > a[j]) {
                    a[k] = (a[k] + a[j] - 1) / a[j];
                    b.push_back(k + 1);
                    c.push_back(j + 1);
                }
            }
            sort(I.begin(), I.end(), [&](int i, int j) {
                    return a[i] < a[j];
                });
            assert(a[I[0]] == a[I[n - 1]]);
            int ans = (int)b.size();
            cout << ans << "\n";
            for (int i = 0; i < ans; ++i) {
                cout << b[i] << " " << c[i] << "\n";
            }
            continue;
        }
        vector<int> b, c;
        while (true) {
            sort(I.begin(), I.end(), [&](int i, int j) {
                    return a[i] < a[j];
                });
            if (a[I[0]] == a[I[n - 1]] || a[I[0]] == 2) { break; }
            for (int i = n - 1; i > 0; --i) {
                int j = I[i - 1], k = I[i];
                while ((a[k] + a[j] - 1) / a[j] > 1) {
                    a[k] = (a[k] + a[j] - 1) / a[j];
                    b.push_back(k + 1);
                    c.push_back(j + 1);
                }
                if (a[k] == 2) { break; }
            }
        }
        sort(I.begin(), I.end(), [&](int i, int j) {
                return a[i] < a[j];
            });
        if (a[I[0]] != a[I[n - 1]]) {
            for (int i = 1; i < n; ++i) {
                int j = I[0], k = I[i];
                while (a[k] > a[j]) {
                    a[k] = (a[k] + a[j] - 1) / a[j];
                    b.push_back(k + 1);
                    c.push_back(j + 1);
                }
            }
        }
        sort(I.begin(), I.end(), [&](int i, int j) {
                return a[i] < a[j];
            });
        assert(a[I[0]] == a[I[n - 1]]);
        int ans = (int)b.size();
        cout << ans << "\n";
        assert(ans <= 30 * n);
        for (int i = 0; i < ans; ++i) {
            cout << b[i] << " " << c[i] << "\n";
        }
    }
}
