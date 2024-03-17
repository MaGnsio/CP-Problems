/**
 *    author:  MaGnsi0
 *    created: 19.12.2023 12:32:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int n = (int)s.size();
        int ones = count(s.begin(), s.end(), '1');
        int zeros = n - ones;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                if (zeros) {
                    zeros--;
                } else {
                    break;
                }
            } else {
                if (ones) {
                    ones--;
                } else {
                    break;
                }
            }
        }
        cout << zeros + ones << "\n";
    }
}
