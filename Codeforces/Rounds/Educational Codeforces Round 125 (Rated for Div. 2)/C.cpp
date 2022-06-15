/**
 *    author:  MaGnsi0
 *    created: 22.03.2022 16:38:59
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
        int c = 0, r = n;
        for (int i = 0; i + 1 < n; i += 2) {
            if (s[i] == ')' && s[i + 1] == '(') {
                bool ok = false;
                for (int j = i + 1; j < n; ++j) {
                    if (s[j] == ')') {
                        r -= (j - i + 1);
                        i = j - 1;
                        c++;
                        ok = true;
                        break;
                    }
                }
                if (!ok) {
                    break;
                }
            } else {
                r -= 2;
                c++;
            }
        }
        cout << c << " " << r << "\n";
    }
}
