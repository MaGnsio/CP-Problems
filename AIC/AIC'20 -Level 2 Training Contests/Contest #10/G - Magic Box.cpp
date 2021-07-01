//https://vjudge.net/contest/436257#problem/G
#include <bits/stdc++.h>
using namespace std;
const int N = 1e8 + 1;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int Q, Cur = 0;
    cin >> Q;
    bitset<N> B(0);
    while (Q--) {
        int T, X;
        cin >> T >> X;
        if (T == 1) {
            Cur += (B[X] == 0);
            B[X] = 1;
        } else {
            Cur -= (B[X] == 1);
            B[X] = 0;
        }
        cout << Cur << "\n";
    }
}

