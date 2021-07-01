//https://atcoder.jp/contests/abc199/tasks/abc199_c
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, Q;
    string S;
    cin >> N >> S >> Q;
    bool flip = false;
    while (Q--) {
        int x, a, b;
        cin >> x >> a >> b;
        if (x == 1) {
            if (flip) {
                swap(S[(a - 1 + N) % (2 * N)], S[(b - 1 + N) % (2 * N)]);
            } else {
                swap(S[a - 1], S[b - 1]);
            }
        } else {
            flip = (!flip);
        }
    }
    if (flip) {
        string A = S.substr(0, N), B = S.substr(N, N);
        S = B + A;
    }
    cout << S;
}
