/**
 *    author:  MaGnsi0
 *    created: 13.03.2022 17:37:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string ans = "";
        for (int i = n; i > 0; ) {
            if (ans.empty() || ans.back() == '1') {
                if (i >= 2) {
                    ans += '2';
                    i -= 2;
                } else {
                    ans = "";
                    break;
                }
            } else {
                if (i >= 1) {
                    ans += '1';
                    i -= 1;
                } else {
                    ans = "";
                    break;
                }
            }
        }
        if (ans == "") {
            for (int i = n; i > 0; ) {
                if (ans.empty() || ans.back() == '2') {
                    if (i >= 1) {
                        ans += '1';
                        i -= 1;
                    } else {
                        ans = "";
                        break;
                    }
                } else {
                    if (i >= 2) {
                        ans += '2';
                        i -= 2;
                    } else {
                        ans = "";
                        break;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}
