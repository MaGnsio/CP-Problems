/**
 *    author:  MaGnsi0
 *    created: 14.02.2023 17:23:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        vector<int> a;
        for (int i = x; i >= y; --i) {
            a.push_back(i);
        }
        for (int i = y + 1; i <= x - 1; ++i) {
            a.push_back(i);
        }
        int n = (int)a.size();
        cout << n << "\n";
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}
