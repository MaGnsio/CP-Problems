/**
 *    author:  MaGnsi0
 *    created: 24/09/2021 18:33:26
**/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    vector<int> P(N, -1), idx(N, -1), O;
    for (int x = 1, y = 1, flag = 0; x < N && y < N; flag ^= 1) {
        P[min(x, y)] = max(x, y);
        if (flag) {
            y += x;
        } else {
            x += y;
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (idx[x] == -1) {
            idx[x] = i + 1;
        }
        if (x == 1) {
            O.push_back(i + 1);
        }
    }
    if ((int)O.size() >= 2) {
        cout << O[0] << " " << O[1];
        return 0;
    }
    for (int i = 0; i < N; ++i) {
        if (idx[i] == -1) {
            continue;
        }
        if (P[i] == -1 || idx[P[i]] == -1) {
            continue;
        }
        int x = idx[i], y = idx[P[i]];
        if (x == y) {
            continue;
        }
        cout << x << " " << y;
        return 0;
    }
    cout << "impossible";
}
