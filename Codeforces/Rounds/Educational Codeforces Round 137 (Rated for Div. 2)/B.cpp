/**
 *    author:  MaGnsi0
 *    created: 17.10.2022 16:39:49
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
        cout << 1 << " " << n;
        for (int i = 2; i < n; ++i) {
            cout << " " << i;
        }
        cout << "\n";
    }
}
