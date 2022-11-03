/**
 *    author:  MaGnsi0
 *    created: 03.09.2022 13:58:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    bool a[7][2] = {{1, 0}, {1, 0}, {1, 1}, {1, 1}, {1, 1}, {1, 0}, {1, 0}};
    if (s[0] == '0') {
        a[3][1] = false;
    }
    if (s[1] == '0') {
        a[2][1] = false;
    }
    if (s[2] == '0') {
        a[4][1] = false;
    }
    if (s[3] == '0') {
        a[1][0] = false;
    }
    if (s[4] == '0') {
        a[3][0] = false;
    }
    if (s[5] == '0') {
        a[5][0] = false;
    }
    if (s[6] == '0') {
        a[0][0] = false;
    }
    if (s[7] == '0') {
        a[2][0] = false;
    }
    if (s[8] == '0') {
        a[4][0] = false;
    }
    if (s[9] == '0') {
        a[6][0] = false;
    }
    bool ok = false;
    for (int i = 0; i < 7; ++i) {
        for (int j = i + 2; j < 7; ++j) {
            bool can = false;
            for (int k = i + 1; k < j; ++k) {
                can |= a[k][0];
                can |= a[k][1];
            }
            ok |= (!can && !a[3][1] && (a[i][0] || a[i][1]) && (a[j][0] || a[j][1]));
        }
    }
    cout << (ok ? "Yes" : "No");
}
