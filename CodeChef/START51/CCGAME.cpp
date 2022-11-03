/**
 *    author:  MaGnsi0
 *    created: 26.09.2022 19:41:36
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
        int nimber = 0;
        for (int i = 0; i < n; ++i) {
            nimber ^= (a[i] % 2) * (n - i - 1);
        }
        cout << (nimber ? "Chef" : "Cook") << "\n";
    }
}
