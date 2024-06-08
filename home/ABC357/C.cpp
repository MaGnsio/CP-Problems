/**
 *    author:  MaGnsi0
 *    created: 08.06.2024 15:10:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m = 1;
    for (int i = 0; i < n; ++i) {
        m *= 3;
    }
    function<vector<string>(int)> solve = [&](int s) {
        if (s == 1) {
            vector<string> carpet(s, string(s, '#'));
            return carpet;
        }
        vector<string> carpet(s, string(s, '#')), block = solve(s / 3);
        block = solve(s / 3);
        for (int i = 0; i < s; ++i) {
            for (int j = 0; j < s; ++j) {
                carpet[i][j] = block[i % (s / 3)][j % (s / 3)];
            }
        }
        for (int i = s / 3, ci = 0; ci < s / 3; ++i, ++ci) {
            for (int j = s / 3, cj = 0; cj < s / 3; ++j, ++cj) {
              carpet[i][j] = '.';
            }
        }
        return carpet;
    };
    vector<string> carpet = solve(m);
    for (int i = 0; i < m; ++i) {
        cout << carpet[i] << "\n";
    }
}