/**
 *    author:  MaGnsi0
 *    created: 26.09.2024 00:38:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int _ = 0; _ < 2; ++_) {
                for (int j = 0; j < n; ++j) {
                    cout << (i & 1 ? ((j & 1 ? "##" : "..")) : (j & 1 ? ".." : "##"));
                }
                cout << "\n";
            }
        }
    }
}
