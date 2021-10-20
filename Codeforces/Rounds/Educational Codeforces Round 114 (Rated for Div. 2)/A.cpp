/**
 *    author:  MaGnsi0
 *    created: 20/09/2021 16:32:53
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<char> v(2 * n);
        for (int i = 0; i < n; ++i) {
            v[i] = '(';
        }
        for (int i = 0; i < n; ++i) {
            v[n + i] = ')';
        }
        for (int i = 0; i < n; ++i) {
            for (auto& c : v) {
                cout << c;
            }
            cout << "\n";
            vector<char> temp(2 * n);
            for (int j = 0; j < 2 * i + 1; ++j) {
                temp[j] = v[j];
            }
            temp[2 * i + 1] = ')';
            for (int j = 2 * i + 1; j < 2 * n - 1; ++j) {
                temp[j + 1] = v[j];
            }
            v = temp;
        }
    }
}
