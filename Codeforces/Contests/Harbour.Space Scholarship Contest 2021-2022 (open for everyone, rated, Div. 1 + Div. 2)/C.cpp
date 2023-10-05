/**
 *    author:  MaGnsi0
 *    created: 22/07/2021 17:11:52
**/
#include <bits/stdc++.h>
using namespace std;

void solve(string s, int& res, int x = 0, int y = 0, int r1 = 5, int r2 = 5, int i = 0) {
    if (i == 10) {
        return;
    }
    if ((x > y + r2) || (y > x + r1)) {
        res = min(res, i);
        return;
    }
    if (s[i] != '?') {
        solve(s, res, x + (i % 2 == 0 && s[i] == '1'), y + (i % 2 != 0 && s[i] == '1'), r1 - (i % 2 == 0), r2 - (i % 2 != 0), i + 1);
    } else {
        solve(s, res, x + (i % 2 == 0), y + (i % 2 != 0), r1 - (i % 2 == 0), r2 - (i % 2 != 0), i + 1);
        solve(s, res, x, y, r1 - (i % 2 == 0), r2 - (i % 2 != 0), i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int res = 10;
        solve(s, res);
        cout << res << "\n";
    }

}
