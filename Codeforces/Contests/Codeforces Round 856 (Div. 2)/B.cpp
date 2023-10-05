/**
 *    author:  MaGnsi0
 *    created: 04.03.2023 19:42:07
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
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) { a[i]++; }
        }
        for (int i = 1; i < n; ++i) {
            if (a[i] % a[i - 1] == 0) { a[i]++; }
        }
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}