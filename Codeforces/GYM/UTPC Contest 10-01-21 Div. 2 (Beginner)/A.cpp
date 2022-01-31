/**
 *    author:  MaGnsi0
 *    created: 22.12.2021 19:26:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    char c;
    cin >> n >> c;
    for (int i = 1; i <= n; ++i) {
        cout << (c == 'a' ? i : n - i + 1) << " ";
    }
}
