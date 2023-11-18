/**
 *    author:  MaGnsi0
 *    created: 18.10.2023 21:47:56
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
        sort(a.begin(), a.end());
        while (!a.empty() && a.back() > 2048) { a.pop_back(); }
        bool ok = false;
        while (true) {
            sort(a.begin(), a.end());
            n = (int)a.size();
            for (int i = 0; i < n; ++i) {
                if (a[i] == 2048) {
                    ok = true;
                }
            }
            if (ok) { break; }
            bool done = true;
            vector<int> b;
            for (int i = 0; i + 1 < n; ++i) {
                if (a[i] == a[i + 1]) {
                    b.push_back(2 * a[i]);
                    for (int j = i + 2; j < n; ++j) {
                        b.push_back(a[j]);
                    }
                    done = false;
                    break;
                } else {
                    b.push_back(a[i]);
                }
            }
            a = b;
            if (done) { break; }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
