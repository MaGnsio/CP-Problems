/**
 *    author:  MaGnsi0
 *    created: 28.12.2023 18:13:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int F[3] = {};
        for (int i = 0; i < 3; ++i) {
            string s; cin >> s;
            for (char c : s) {
                if ('A' <= c && c <= 'C') {
                    F[c - 'A']++;
                }
            }
        }
        for (int i = 0; i < 3; ++i) {
            if (F[i] == 2) {
                cout << char('A' + i) << "\n";
                break;
            }
        }
    }
}
