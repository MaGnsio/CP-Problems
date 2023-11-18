/**
 *    author:  MaGnsi0
 *    created: 31.10.2023 20:30:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t v; cin >> v;
    int64_t n; cin >> n;
    for (int64_t i = 10; i < 100; i += 10) {
        cout << (i * n * v + 99) / 100 << " ";
    }
}
