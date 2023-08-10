/**
 *    author:  MaGnsi0
 *    created: 18.04.2023 00:05:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    for (int i = 0; i < m; ++i) {
        char t;
        cin >> t;
        if (t == 'B') {
            int x, y;
            cin >> x >> y;
            for (int j = 0; j < n; ++j) {
                if (a[j] == x) {
                    x = j;
                    break;
                }
            }
            for (int j = 0; j < n; ++j) {
                if (a[j] == y) {
                    y = j;
                    break;
                }
            }
            swap(a[x], a[y]);
        } else if (t == 'E') {
            int x, y;
            cin >> x >> y;
            swap(a[x - 1], a[y - 1]);
        } else {
            vector<int> b(n);
            for (int j = 0; j < n; ++j) {
                cin >> b[j];
            }
            vector<int> c(n);
            for (int j = 0; j < n; ++j) {
                c[a[j] - 1] = b[j];
            }
            for (int j = 0; j < n; ++j) {
                if (j) { cout << " "; }
                cout << c[j];
            }
            cout << "\n";
        }
    }
}
