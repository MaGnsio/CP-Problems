/**
 *    author:  MaGnsi0
 *    created: 02.04.2022 01:19:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        vector<vector<int>> a(3, vector<int>(4));
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 4; ++j) {
                cin >> a[i][j];
            }
        }
        vector<int> no_more(4, INT_MAX);
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 3; ++j) {
                no_more[i] = min(no_more[i], a[j][i]);
            }
        }
        for (int i = 1; i < 4; ++i) {
            int sum = accumulate(no_more.begin(), no_more.begin() + i, 0);
            no_more[i] = min(no_more[i], (int)1e6 - sum);
        }
        cout << "Case #" << t << ": ";
        if (accumulate(no_more.begin(), no_more.end(), 0) != (int)1e6) {
            cout << "IMPOSSIBLE\n";
        } else {
            for (int i = 0; i < 4; ++i) {
                cout << no_more[i] << " ";
            }
            cout << "\n";
        }
    }
}
