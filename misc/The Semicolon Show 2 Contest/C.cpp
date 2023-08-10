/**
 *    author:  MaGnsi0
 *    created: 06.08.2023 09:22:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n;
        cin >> n;
        cout << n * (n - 1) / 2 << "\n";
    }
}
