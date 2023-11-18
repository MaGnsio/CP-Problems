/**
 *    author:  MaGnsi0
 *    created: 11.10.2023 21:20:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, _; cin >> n >> _;
    for (int i = 0; i < n; ++i) {
        int u = n - i;
        int v = (n - i - 1 == 0 ? n : n - i - 1);
        if (u < v) { swap(u, v); }
        cout << u << " " << v << "\n";
    }
}
