/**
 *    author:  MaGnsi0
 *    created: 05.03.2022 19:21:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        long long n, s;
        cin >> n >> s;
        cout << (s / (n * n)) << "\n";
    }
}
