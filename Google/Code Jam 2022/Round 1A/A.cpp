/**
 *    author:  MaGnsi0
 *    created: 09.04.2022 03:01:16
**/
#include <bits/stdc++.h>
using namespace std;

void WORK() {
    string s;
    cin >> s;
    string t = "";
    for (int i = 0; i < (int)s.size(); ++i) {
        t += s[i];
        char c = char('A' - 1);
        for (int j = i + 1; j < (int)s.size(); ++j) {
            if (s[j] != s[i]) {
                c = s[j];
                break;
            }
        }
        if (s[i] < c) {
            t += s[i];
        }
    }
    cout << t << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        WORK();
    }
}
