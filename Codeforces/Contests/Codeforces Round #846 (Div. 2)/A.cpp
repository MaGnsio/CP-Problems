/**
 *    author:  MaGnsi0
 *    created: 25.01.2023 16:36:18
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
        vector<vector<int>> a(2);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[x % 2].push_back(i + 1);
        }
        if ((int)a[1].size() >= 3) {
            cout << "YES\n";
            cout << a[1][0] << " " << a[1][1] << " " << a[1][2] << "\n";
        } else if ((int)a[1].size() >= 1 && a[0].size() >= 2) {
            cout << "YES\n";
            cout << a[0][0] << " " << a[0][1] << " " << a[1][0] << "\n";
        } else {
            cout << "NO\n";
        }
    }
}
