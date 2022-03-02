/**
 *    author:  MaGnsi0
 *    created: 22.02.2022 16:36:13
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
        bool good = true;
        for (int i = 0; i < 6; ++i) {
            if (isupper(s[i])) {
                bool ok = false;
                for (int j = 0; j < i; ++j) {
                    if (islower(s[j])) {
                        ok |= (s[i] + 32 == s[j]);
                    }
                }
                good &= ok;
            }
        }
        cout << (good ? "YES\n" : "NO\n");
    }
}
