/**
 *    author:  MaGnsi0
 *    created: 07.12.2022 12:57:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    string s;
    int64_t score = 0;
    while (getline(cin, s)) {
        char X = s[0], Y = (s[2] == 'X' ? 'A' : (s[2] == 'Y' ? 'B' : 'C'));
        score += (Y == 'A' ? 1 : (Y == 'B' ? 2 : 3));
        score += (Y == X) * 3;
        score += 6 * ((Y == 'A' && X == 'C') + (Y == 'B' && X == 'A') + (Y == 'C' && X == 'B'));
    }
    cout << score;
}
