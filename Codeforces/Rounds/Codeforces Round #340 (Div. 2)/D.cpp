/**
 *    author:  MaGnsi0
 *    created: 17.02.2023 18:00:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> x(3), y(3);
    for (int i = 0; i < 3; ++i) {
        cin >> x[i] >> y[i];
    }
    if (x[0] == x[1] && x[1] == x[2]) {
        cout << 1;
        return 0;
    }
    if (y[0] == y[1] && y[1] == y[2]) {
        cout << 1;
        return 0;
    }
    int ans = 3;
    vector<int> I(3);
    iota(I.begin(), I.end(), 0);
    do {
        if (x[I[0]] == x[I[1]] && y[I[2]] <= min(y[I[0]], y[I[1]])) {
            ans = 2;
        }
        if (x[I[0]] == x[I[1]] && y[I[2]] >= max(y[I[0]], y[I[1]])) {
            ans = 2;
        }
        if (x[I[1]] == x[I[2]] && y[I[0]] <= min(y[I[1]], y[I[2]])) {
            ans = 2;
        }
        if (x[I[1]] == x[I[2]] && y[I[0]] >= max(y[I[1]], y[I[2]])) {
            ans = 2;
        }
        if (y[I[0]] == y[I[1]] && x[I[2]] <= min(x[I[0]], x[I[1]])) {
            ans = 2;
        }
        if (y[I[0]] == y[I[1]] && x[I[2]] >= max(x[I[0]], x[I[1]])) {
            ans = 2;
        }
        if (y[I[1]] == y[I[2]] && x[I[0]] <= min(x[I[1]], x[I[2]])) {
            ans = 2;
        }
        if (y[I[1]] == y[I[2]] && x[I[0]] >= max(x[I[1]], x[I[2]])) {
            ans = 2;
        }
    } while (next_permutation(I.begin(), I.end()));
    cout << ans;
}
