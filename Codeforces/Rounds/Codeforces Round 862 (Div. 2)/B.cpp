/**
 *    author:  MaGnsi0
 *    created: 02.04.2023 16:39:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        if (n == 1) {
            cout << s << "\n";
            continue;
        }
        char min_c = *min_element(s.begin() + 1, s.end());
        if (min_c > s[0]) {
            cout << s << "\n";
            continue;
        }
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == min_c) {
                s[i] = '*';
                break;
            }
        }
        cout << min_c;
        for (int i = 0; i < n; ++i) {
            if (s[i] != '*') {
                cout << s[i];
            }
        }
        cout << "\n";
    }
}
