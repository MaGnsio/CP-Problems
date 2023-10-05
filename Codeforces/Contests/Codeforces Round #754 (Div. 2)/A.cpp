/**
 *    author:  MaGnsi0
 *    created: 12.11.2021 19:44:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << (abs((a + c) - (2 * b)) % 3 ? 1 : 0) << "\n";
    }
}
