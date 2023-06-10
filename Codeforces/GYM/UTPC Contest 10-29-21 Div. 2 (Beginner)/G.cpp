/**
 *    author:  MaGnsi0
 *    created: 14.05.2023 21:47:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t x, y;
    cin >> x >> y;
    string s;
    cin >> s;
    int64_t X = count(s.begin(), s.end(), 'R') - count(s.begin(), s.end(), 'L');
    int64_t Y = count(s.begin(), s.end(), 'U') - count(s.begin(), s.end(), 'D');
    bool ok = false;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (X == 0 && Y == 0) {
            ok |= ((x == 0) && (y == 0));
        } else if (X == 0) {
            ok |= (((Y < 0) == (y < 0)) && (abs(y) % abs(Y) == 0));
        } else if (Y == 0) {
            ok |= (((X < 0) == (x < 0)) && (abs(x) % abs(X) == 0));
        } else {
            ok |= (((X < 0) == (x < 0)) && (abs(x) % abs(X) == 0) && ((Y < 0) == (y < 0)) && (abs(y) % abs(Y) == 0) && (abs(y) / abs(Y) == abs(x) / abs(X)));
        }
        if (s[i] == 'R') { x--; } 
        if (s[i] == 'L') { x++; }
        if (s[i] == 'U') { y--; }
        if (s[i] == 'D') { y++; }
    }
    cout << (ok ? "Yes" : "No");
}
