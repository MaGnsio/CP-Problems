/**
 *    author:  MaGnsi0
 *    created: 22.04.2022 09:57:30
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
        bool ok = true;
        int cntR = 0, cntB = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'W') {
                if (!cntR && !cntB) {
                    continue;
                }
                if (!cntR || !cntB) {
                    ok = false;
                }
                cntR = 0, cntB = 0;
            } else {
                if (s[i] == 'R') {
                    cntR++;
                } else {
                    cntB++;
                }
            }
        }
        if ((cntR || cntB) && (!cntR || !cntB)) {
            ok = false;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
