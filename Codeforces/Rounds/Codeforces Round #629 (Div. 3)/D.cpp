/**
 *    author:  MaGnsi0
 *    created: 10.12.2021 00:22:11
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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        set<int> s;
        for (int i = 0; i < n; ++i) {
            s.insert(a[i]);
        }
        int x = s.size();
        if (x == 1) {
            cout << 1 << "\n";
            for (int i = 0; i < n; ++i) {
                cout << 1 << " ";
            }
        } else if (n % 2 == 0) {
            cout << 2 << "\n";
            for (int i = 0; i < n; ++i) {
                cout << (i & 1 ? 2 : 1) << " ";
            }
        } else {
            bool ok = false;
            for (int i = 1; i <= n; ++i) {
                ok |= (a[i % n] == a[i - 1]);
            }
            if (ok) {
                cout << 2 << "\n";
                vector<int> res(n);
                for (int i = 0; i < n; ++i) {
                    res[i] = (i % 2) + 1;
                }
                for (int i = 1; i < n; ++i) {
                    if (a[i] == a[i - 1]) {
                        for (int j = i; j < n; ++j) {
                            res[j] = (res[j] == 1 ? 2 : 1);
                        }
                        break;
                    }
                }
                for (int i = 0; i < n; ++i) {
                    cout << res[i] << " ";
                }
            } else {
                cout << 3 << "\n";
                for (int i = 0; i < n; ++i) {
                    cout << (i == n - 1 ? 3 : (i % 2) + 1) << " ";
                }
            }
        }
        cout << "\n";
    }
}
