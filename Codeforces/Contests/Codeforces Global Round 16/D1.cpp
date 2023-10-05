/**
 *    author:  MaGnsi0
 *    created: 12/09/2021 16:29:24
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> v(m);
        for (int i = 0; i < m; ++i) {
            cin >> v[i];
        }
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (v[j] < v[i]) {
                    res++;
                }
            }
        }
        cout << res << "\n";
    }
}
