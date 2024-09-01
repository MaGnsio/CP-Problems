/**
 *    author:  MaGnsi0
 *    created: 01.09.2024 18:37:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int L; cin >> L;
        int R; cin >> R;
        int N = 0, D = 1;
        while (L <= R) {
            L += D; N++; D++;
        }
        cout << N << "\n";
    }
}
