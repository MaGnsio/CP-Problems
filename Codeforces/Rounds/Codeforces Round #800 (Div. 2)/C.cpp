/**
 *    author:  MaGnsi0
 *    created: 16.06.2022 16:35:00
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
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        while (!a.empty() && a.back() == 0) {
            a.pop_back();
        }
        n = (int)a.size();
        if (!n) {
            cout << "YES\n";
            continue;
        }
        if (a[0] < 0 || a[n - 1] > 0) {
            cout << "NO\n";
            continue;
        }
        if (n == 1) {
            cout << "NO\n";
            continue;
        }
        vector<int64_t> left(n, 0), right(n, 0);
        right[0] = a[0];
        left[n - 1] = -a[n - 1];
        for (int i = 1; i < n - 1; ++i) {
            left[i] = right[i - 1] + left[i - 1] - (i - 2 >= 0 ? right[i - 2] - (i - 2 == 0) : 1);
            right[i] = (a[i] + left[i]);
        }
        bool ok = true;
        for (int i = 1; i < n - 1; ++i) {
            ok &= bool(left[i] >= 0 && right[i] >= 0);
        }
        cout << (ok && left[n - 1] == right[n - 2] + 1 ? "YES" : "NO") << "\n";
    }
}
