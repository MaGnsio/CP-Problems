/**
 *    author:  MaGnsi0
 *    created: 22.07.2023 11:04:06
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("endure.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        string _; cin >> _;
        int64_t Y, S;
        cin >> Y >> S;
        cout << 365 * 24 * 60 * 60 * Y * S << "\n";
    }
}
