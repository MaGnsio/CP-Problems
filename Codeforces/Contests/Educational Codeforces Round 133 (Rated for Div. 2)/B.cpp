/**
 *    author:  MaGnsi0
 *    created: 04.08.2022 16:34:21
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
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        cout << n << "\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << a[j] << " ";
            }
            cout << "\n";
            if (i == 0) {
                swap(a[0], a[1]);
            } else if (i != n - 1) {
                int fixed = -1;
                for (int j = 0; j < n; ++j) {
                    if (a[j] == j + 1) {
                        fixed = j;
                        break;
                    }
                }
                int not_fixed = -1;
                for (int j = 0; j < n; ++j) {
                    if (a[j] != j + 1 && a[j] != fixed + 1) {
                        not_fixed = j;
                        break;
                    }
                }
                swap(a[fixed], a[not_fixed]);
            }
        }
    }
}
