/**
 *    author:  MaGnsi0
 *    created: 24.07.2022 16:34:26
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
        for (int i = 2; i <= n; ++i) {
            cout << i << " ";
        }
        cout << 1 << "\n";
    }
}
