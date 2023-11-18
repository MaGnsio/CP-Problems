/**
 *    author:  MaGnsi0
 *    created: 24.10.2023 04:38:52
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<vector<bool>> is_empty(N, vector<bool>(N, true));
    while (n--) {
        int d; cin >> d;
        int l; cin >> l;
        int r; cin >> r; r--;
        int c; cin >> c; c--;
        if (d == 0) {
            for (int j = c; j < c + l; ++j) {
                if (j >= N || !is_empty[r][j]) {
                    cout << "N";
                    return 0;
                }
                is_empty[r][j] = false;
            }
        } else {
            for (int i = r; i < r + l; ++i) {
                if (i >= N || !is_empty[i][c]) {
                    cout << "N";
                    return 0;
                }
                is_empty[i][c] = false;
            }
        }
    }
    cout << "Y";
}
