/**
 *    author:  MaGnsi0
 *    created: 09.06.2022 21:13:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int64_t>> C(n + 1, vector<int64_t>(n + 1));
    for (int i = 1; i <= n; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= n; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }
}
