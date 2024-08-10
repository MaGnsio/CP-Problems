/**
 *    author:  MaGnsi0
 *    created: 10.08.2024 17:37:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int x; cin >> x;
        int y; cin >> y;
        int k; cin >> k;
        vector<int> X(k), Y(k);
        if (k & 1) {
            for (int i = 0, j = 1; i < k - 1; i += 2, ++j) {
                if (j == abs(k * x)) { j++; }
                X[i] = j;
                X[i + 1] = -j;
            }
            X[k - 1] = k * x;
            for (int i = 0, j = 1; i < k - 1; i += 2, ++j) {
                if (j == abs(k * y)) { j++; }
                Y[i] = j;
                Y[i + 1] = -j;
            }
            Y[k - 1] = k * y;
        } else {
            X[k - 2] = k, X[k - 1] = k * (x - 1);
            for (int i = 0, j = 1; i < k - 2; i += 2, ++j) {
                if (j == abs(k * (x - 1)) || j == k) { j++; }
                X[i] = j;
                X[i + 1] = -j;
            }
            Y[k - 2] = k, Y[k - 1] = k * (y - 1);
            for (int i = 0, j = 1; i < k - 2; i += 2, ++j) {
                if (j == abs(k * (y - 1)) || j == k) { j++; }
                Y[i] = j;
                Y[i + 1] = -j;
            }
        }
        int sumx = 0, sumy = 0;
        for (int i = 0; i < k; ++i) {
            cout << X[i] << " " << Y[i] << "\n";
            sumx += X[i], sumy += Y[i];
        }
        assert(sumx / k == x && sumy / k == y);
    }
}
