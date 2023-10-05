/**
 *    author:  MaGnsi0
 *    created: 20.03.2023 02:03:52
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
        cout << (a + b == c ? "+" : "-") << "\n";
    }
}
