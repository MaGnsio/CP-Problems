/**
 *    author:  MaGnsi0
 *    created: 21.07.2023 17:39:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n = 8;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        string ans = "";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] == '.') { continue; }
                for (int k = i; k < n; ++k) {
                    if (a[k][j] == '.') { goto end; }
                    ans += a[k][j];
                }
                goto end;
            }
        }
        end:
        cout << ans << "\n";
    }
}
