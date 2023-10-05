/**
 *    author:  MaGnsi0
 *    created: 31.03.2022 21:11:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        cout << (a == 0 ? 1 : a + 2 * b + 1) << "\n";
    }
}
