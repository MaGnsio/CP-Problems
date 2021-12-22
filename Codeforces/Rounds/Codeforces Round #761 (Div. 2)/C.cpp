/**
 *    author:  MaGnsi0
 *    created: 16.12.2021 15:20:58
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

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
        for (int i = 1; i <= n; ++i) {
            s.insert(i);
        }
        vector<int> b;
        for (int i = 0; i < n; ++i) {
            if (s.count(a[i])) {
                s.erase(a[i]);
            } else {
                b.push_back(a[i]);
            }
        }
        sort(b.begin(), b.end());
        vector<int> c(s.begin(), s.end());
        bool ok = true;
        for (int i = 0; i < (int)b.size(); ++i) {
            if (2 * c[i] + 1 > b[i]) {
                ok = false;
            }
        }
        cout << (ok ? (int)b.size() : -1) << "\n";
    }
}
