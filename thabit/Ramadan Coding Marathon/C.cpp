/**
 *    author:  MaGnsi0
 *    created: 07.04.2022 17:51:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        cout << min((n + 1) / 2, k / 2) << "\n";
    }
}
