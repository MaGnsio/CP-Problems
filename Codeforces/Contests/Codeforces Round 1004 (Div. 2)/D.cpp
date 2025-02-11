/**
 *    author:  MaGnsi0
 *    created: 11.02.2025 17:05:48
**/
#include <bits/stdc++.h>

using namespace std;

int ask(int i, int j) {
    cout << "? " << i + 1 << " " << j + 1 << endl;
    int x; cin >> x; return x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; a[i]--;
        }
        vector<bool> out(n, false);
        for (int i = 0; i < n; ++i) {
            out[a[i]] = true;
        }
        if (count(out.begin(), out.end(), false)) {
            for (int i = 0; i < n; ++i) {
                if (out[i] == false) {
                    if (ask(i, (i ? 0 : 1))) {
                        cout << "! B" << endl;
                    } else {
                        cout << "! A" << endl;
                    }
                    break;
                }
            }
        } else {
            int p1 = -1, pn = -1;
            for (int i = 0; i < n; ++i) {
                if (a[i] == 0) { p1 = i; }
                if (a[i] == n - 1) { pn = i; }
            }
            int x = ask(p1, pn);
            if (x < n - 1) {
                cout << "! A" << endl;
            } else if (x > n - 1) {
                cout << "! B" << endl;
            } else {
                assert(x == n - 1);
                int x = ask(pn, p1);
                if (x <= 1) {
                    cout << "! A" << endl;
                } else {
                    cout << "! B" << endl;
                }
            }
        }
    }
}
