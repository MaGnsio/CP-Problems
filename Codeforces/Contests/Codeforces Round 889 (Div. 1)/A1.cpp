/**
 *    author:  MaGnsi0
 *    created: 29.07.2023 19:00:32
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
        if (count(a.begin(), a.end(), 0) == n) {
            cout << 0 << "\n";
            continue;
        }
        vector<int> b, c;
        for (int i = 1; i < n; ++i) {
            if (a[i] >= a[i - 1]) { continue; }
            if (a[i - 1] >= 0 && a[i] >= 0) {
                a[i] += a[i - 1];
                b.push_back(i + 1);
                c.push_back(i);
            } else if (a[i - 1] > 0 && a[i] <= 0) {
                while (abs(a[i]) > abs(a[i - 1])) {
                    a[i - 1] += a[i - 1];
                    b.push_back(i);
                    c.push_back(i);
                }
                a[i] += a[i - 1];
                a[i] += a[i - 1];
                b.push_back(i + 1);
                c.push_back(i);
                b.push_back(i + 1);
                c.push_back(i);
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (a[i] <= a[i + 1]) { continue; }
            if (a[i] <= 0 && a[i + 1] <= 0) {
                a[i] += a[i + 1];
                b.push_back(i + 1);
                c.push_back(i + 2);
            }
        }
        cout << (int)b.size() << "\n";
        assert((int)b.size() <= 50);
        for (int i = 1; i < n; ++i) {
            assert(a[i] >= a[i - 1]);
        }
        for (int i = 0; i < (int)b.size(); ++i) {
            cout << b[i] << " " << c[i] << "\n";
        }
    }
}
