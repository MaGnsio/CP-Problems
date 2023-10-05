/**
 *    author:  MaGnsi0
 *    created: 03/10/2021 16:36:52
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, h;
        cin >> n >> h;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        sort(v.begin(), v.end(), greater<int>());
        int a = v[0], b = v[1];
        if (h % (a + b) == 0) {
            cout << 2 * (h / (a + b)) << "\n";
        } else if (h % (a + b) <= a) {
            cout << 2 * (h / (a + b)) + 1 << "\n";
        } else {
            cout << 2 * (h / (a + b)) + 2 << "\n";
        }
    }
}
