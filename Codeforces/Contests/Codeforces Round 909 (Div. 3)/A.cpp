/**
 *    author:  MaGnsi0
 *    created: 28.11.2023 21:35:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        cout << (n % 3 ? "First" : "Second") << "\n";
    }
}
