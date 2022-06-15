/**
 *    author:  MaGnsi0
 *    created: 30.04.2022 16:34:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int64_t Alice = 0, Bob = 0;
        if ((int)s.size() & 1) {
            for (int i = 1; i < (int)s.size() - 1; ++i) {
                Alice += s[i] - 'a' + 1;
            }
            if ((int)s.size() > 1) {
                Alice += max(s[0] - 'a' + 1, s.back() - 'a' + 1);
            }
            Bob += min(s[0] - 'a' + 1, s.back() - 'a' + 1);
        } else {
            for (int i = 0; i < (int)s.size(); ++i) {
                Alice += s[i] - 'a' + 1;
            }
        }
        cout << (Alice > Bob ? "Alice" : "Bob") << " ";
        cout << abs(Alice - Bob) << "\n";
    }
}
