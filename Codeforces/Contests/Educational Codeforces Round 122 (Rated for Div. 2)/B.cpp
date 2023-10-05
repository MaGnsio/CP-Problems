/**
 *    author:  MaGnsi0
 *    created: 31.01.2022 23:26:29
**/
#include <bits/stdc++.h>

using namespace std;

int solve(string s) {
    int x = count(s.begin(), s.end(), '1');
    int y = count(s.begin(), s.end(), '0');
    return min(x, y);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int x = count(s.begin(), s.end(), '1');
        int y = count(s.begin(), s.end(), '0');
        cout << (x == y ? min(solve(s.substr(1)), solve(s.substr(0, (int)s.size() - 1))) : min(x, y)) << "\n";
    }
}
