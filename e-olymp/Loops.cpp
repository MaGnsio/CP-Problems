//https://www.e-olymp.com/en/contests/15927/problems/164104
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, ok = 0;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1, x; j <= N; ++j) {
            cin >> x;
            if (i == j && x == 1) {
                ok = 1;
            }
        }
    }
    cout << (ok ? "YES" : "NO");
}

