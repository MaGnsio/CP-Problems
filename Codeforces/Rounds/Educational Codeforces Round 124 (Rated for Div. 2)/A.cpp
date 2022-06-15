/**
 *    author:  MaGnsi0
 *    created: 10.03.2022 16:30:27
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
        cout << (1LL << n) - 1 << "\n";
    }
}
