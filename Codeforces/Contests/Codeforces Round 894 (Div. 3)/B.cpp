/**
 *    author:  MaGnsi0
 *    created: 24.08.2023 17:40:27
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
        vector<int> a, b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        a.push_back(b[0]);
        for (int i = 1; i < n; ++i) {
            if (b[i] >= a.back()) {
                a.push_back(b[i]);
            } else {
                a.push_back(b[i--]);
            }
        }
        int m = (int)a.size();
        cout << m << "\n";
        for (int i = 0; i < m; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}
