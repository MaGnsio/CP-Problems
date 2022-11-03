/**
 *    author:  MaGnsi0
 *    created: 04.09.2022 15:36:35
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, m;
    cin >> n >> m;
    if (m == 1) {
        cout << (n - 1);
    } else {
        cout << n * (m - 1);
    }
}
