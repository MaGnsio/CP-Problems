/**
 *    author:  MaGnsi0
 *    created: 22.02.2022 16:40:48
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
        vector<int> a(n, 1);
        for (int i = 1; i < n; ++i) {
            a[i] = n - i + 1;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << a[j] << " ";
            }
            cout << "\n";
            if (i < n - 1) {
                swap(a[i], a[i + 1]);
            }
        }
    }
}
