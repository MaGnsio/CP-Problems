/**
 *    author:  MaGnsi0
 *    created: 20.06.2023 15:59:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << (n == m ? "Square" : "Rectangle") << "\n";
    }
}
