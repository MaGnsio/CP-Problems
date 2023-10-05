/**
 *    author:  MaGnsi0
 *    created: 24.08.2023 17:36:17
**/
#include <bits/stdc++.h>

using namespace std;

const string name = "vika";

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int k = 0;
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                if (a[i][j] == name[k]) {
                    k++;
                    break;
                }
            }
            if (k == 4) { break; }
        }
        cout << (k == 4 ? "YES" : "NO") << "\n";
    }
}
