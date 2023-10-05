/**
 *    author:  MaGnsi0
 *    created: 05/10/2021 01:14:23
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n <= 3) {
            cout << "-1\n";
            continue;
        }
        if (n == 4) {
            cout << "3 1 4 2\n";
            continue;
        }
        vector<int> p;
        for (int i = 1; i <= n; i += 2) {
            p.push_back(i);
        }
        if (n & 1) {
            p.push_back(n - 3);
        } else {
            p.push_back(n - 4);
        }
        for (int i = n - (n & 1); i >= 2; i -= 2) {
            if ((n & 1) && (i == n - 3)) {
                continue;
            }
            if ((n % 2 == 0) && (i == n - 4)) {
                continue;
            }
            p.push_back(i);
        }
        assert((int)p.size() == n);
        for (int i = 0; i < n - 1; ++i) {
            assert(abs(p[i] - p[i + 1]) >= 2);
            assert(abs(p[i] - p[i + 1]) <= 4);
        }
        for (int i = 0; i < n; ++i) {
            cout << p[i] << " ";
        }
        cout << "\n";
   }
}
