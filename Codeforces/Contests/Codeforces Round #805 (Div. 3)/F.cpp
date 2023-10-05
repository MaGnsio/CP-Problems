/**
 *    author:  MaGnsi0
 *    created: 10.07.2022 16:32:30
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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        multiset<int> s;
        for (int i = 0; i < n; ++i) {
            s.insert(a[i]);
        }
        function<int(int)> solve = [&](int x) {
            while (x <= a[n - 1]) {
                if (s.count(x)) {
                    return x;
                }
                x *= 2;
            }
            return -1;
        };
        for (int i = 0; i < n; ++i) {
            int x = b[i];
            while (x) {
                int y = solve(x);
                if (y != -1) {
                    s.erase(s.find(y));
                    break;
                }
                x /= 2;
            }
        }
        cout << (s.empty() ? "YES" : "NO") << "\n";
    }
}
