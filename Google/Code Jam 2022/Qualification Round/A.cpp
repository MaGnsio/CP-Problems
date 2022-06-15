/**
 *    author:  MaGnsi0
 *    created: 02.04.2022 01:02:58
**/
#include <bits/stdc++.h>

using namespace std;

void print_art(int R, int C) {
    for (int i = 0; i < 2 * R + 1; ++i) {
        for (int j = 0; j < 2 * C + 1; ++j) {
            if (i & 1) {
                if (i == 1) {
                    cout << (j % 2 == 0 && j ? '|' : '.');
                } else {
                    cout << (j % 2 == 0 ? '|' : '.');
                }
            } else {
                if (i == 0) {
                    cout << (j < 2 ? '.' : (j & 1 ? '-' : '+'));
                } else {
                    cout << (j & 1 ? '-' : '+');
                }
            }
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int R, C;
        cin >> R >> C;
        cout << "Case #" << t << ":\n";
        print_art(R, C);
    }
}
