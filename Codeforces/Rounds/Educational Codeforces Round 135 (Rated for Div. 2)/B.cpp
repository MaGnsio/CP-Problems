/**
 *    author:  MaGnsi0
 *    created: 11.12.2022 14:49:18
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
        reverse(a.begin(), a.begin() + n - 2);
        if (n & 1) { swap(a[0], a[1]); }
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}
