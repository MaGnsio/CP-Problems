/**
 *    author:  MaGnsi0
 *    created: 23.12.2023 14:02:44
**/
#include <bits/stdc++.h>

using namespace std;

const __int128 OO = 3e18;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t A, M, L, R;
    cin >> A >> M >> L >> R;
    __int128 B = __int128(A) - __int128(M) * ((OO + M - 1) / M);
    function<int64_t(int64_t)> F = [&](int64_t x) {
        assert(B < x);
        __int128 D = x - B + 1;
        return (D + M - 1) / M;
    };
    cout << F(R) - F(L - 1);
}
