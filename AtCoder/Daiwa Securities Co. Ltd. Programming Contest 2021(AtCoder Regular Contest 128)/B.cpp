/**
 *    author:  MaGnsi0
 *    created: 15.11.2021 20:16:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int A[3];
        for (int i = 0; i < 3; ++i) {
            cin >> A[i];
        }
        sort(A, A + 3);
        int res = -1;
        do {
            if (abs(A[0] - A[1]) % 3) {
                continue;
            }
            int x = max(A[0], A[1]);
            if (res == -1 || x < res) {
                res = x;
            }
        } while (next_permutation(A, A + 3));
        cout << res << "\n";
    }
}
