/**
 *    author:  MaGnsi0
 *    created: 25.10.2022 07:36:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    for (int i = 0; i < H; ++i) {
        cin >> a[i];
    }
    vector<int> X(W);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            X[j] += a[i][j] == '#';
        }
    }
    for (int i = 0; i < W; ++i) {
        cout << X[i] << " ";
    }
}
