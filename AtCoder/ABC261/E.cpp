/**
 *    author:  MaGnsi0
 *    created: 25.07.2022 15:16:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t N, C;
    cin >> N >> C;
    int64_t X = (1LL << 31) - 1, Y = 0;
    for (int i = 0; i < N; ++i) {
        int t, a;
        cin >> t >> a;
        if (t == 1) {
            X &= a;
            Y &= a;
        } else if (t == 2) {
            X |= a;
            Y |= a;
        } else {
            X ^= a;
            Y ^= a;
        }
        int64_t nC = 0;
        for (int j = 0; j <= 30; ++j) {
            if (((C >> j) & 1) && ((X >> j) & 1)) {
                nC |= (1 << j);
            }
            if (!((C >> j) & 1) && ((Y >> j) & 1)) {
                nC |= (1 << j);
            }
        }
        C = nC;
        cout << C << "\n";
    }
}
