/**
 *    author:  MaGnsi0
 *    created: 31.01.2023 21:11:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        vector<vector<int>> a(2, vector<int>(2));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                cin >> a[i][j];
            }
        }
        function<bool()> good = [&]() {
            if (a[0][0] > a[0][1]) { return false; }
            if (a[1][0] > a[1][1]) { return false; }
            if (a[0][0] > a[1][0]) { return false; }
            if (a[0][1] > a[1][1]) { return false; }
            return true;
        };
        function<void()> rotate = [&]() {
            vector<vector<int>> b(2, vector<int>(2));
            b[0][0] = a[1][0], b[0][1] = a[0][0];
            b[1][0] = a[1][1], b[1][1] = a[0][1];
            a = b;
        };
        for (int i = 0; i < 4; ++i) {
            if (good()) { break; }
            rotate();
        }
        cout << (good() ? "YES" : "NO") << "\n";
    }
}
