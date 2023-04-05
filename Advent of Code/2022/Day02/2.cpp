/**
 *    author:  MaGnsi0
 *    created: 07.12.2022 12:57:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("2.in", "r", stdin);
    freopen("2.out", "w", stdout);
    string s;
    int64_t score = 0;
    while (getline(cin, s)) {
        char X = s[0], Y = s[2];
        score += (Y == 'X' ? 0 : (Y == 'Y' ? 3 : 6));
        if (X == 'A') {
            score += (Y == 'X' ? 3 : (Y == 'Y' ? 1 : 2));
        } else if (X == 'B') {
            score += (Y == 'X' ? 1 : (Y == 'Y' ? 2 : 3));
        } else {
            score += (Y == 'X' ? 2 : (Y == 'Y' ? 3 : 1));
        }
    }
    cout << score;
}
