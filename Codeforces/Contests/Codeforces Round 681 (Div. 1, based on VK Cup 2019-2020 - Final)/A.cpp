/**
 *    author:  MaGnsi0
 *    created: 09.01.2024 22:22:58
**/
#include <bits/stdc++.h>

using namespace std;

bool F(vector<int> a, bool is_reverse) {
    int n = (int)a.size();
    if (is_reverse) {
        reverse(a.begin(), a.end());
    }
    int ops = a[0];
    a[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] >= a[i - 1]) {
            int new_ops = min(ops, a[i] - a[i - 1]);
            a[i] -= new_ops;
            ops = new_ops;
        } else {
            return false;
        }
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) { return false; }
    }
    return true;
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << (F(a, false) || F(a, true) ? "YES" : "NO") << "\n";
    }
}
