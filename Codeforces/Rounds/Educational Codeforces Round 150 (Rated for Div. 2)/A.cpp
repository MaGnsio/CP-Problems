/**
 *    author:  MaGnsi0
 *    created: 14.06.2023 02:34:10
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
        cout << (n > 4 ? "Alice" : "Bob") << "\n";
    }
}
