/**
 *    author:  MaGnsi0
 *    created: 21.09.2022 23:15:58
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
        int nim_sum = 0;
        for (int i = 0; i < n; ++i) {
            nim_sum ^= a[i];
        }
        cout << (nim_sum ? "First" : "Second") << "\n";
    }
}
