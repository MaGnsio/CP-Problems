/**
 *    author:  MaGnsi0
 *    created: 06.08.2023 09:04:30
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    cout << (n == 1 ? "QWERTY" : (n == 2 ? "DVORAK" : "AZERTY"));
}
