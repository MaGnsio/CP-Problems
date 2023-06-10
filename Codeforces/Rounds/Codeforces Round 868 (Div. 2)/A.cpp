/**
 *    author:  MaGnsi0
 *    created: 04.05.2023 17:43:04
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int K = N * (N - 1) / 2;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vector<pair<int, int>>> mp(N, vector<pair<int, int>>(K, {-1, -1}));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i + j >= N) { break; }
            int k = (i * (i - 1) + j * (j - 1)) / 2;
            if (k >= K) { break; }
            mp[i + j][k] = make_pair(i, j);
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        if (mp[n][k].first == -1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 0; i < mp[n][k].first; ++i) {
                cout << 1 << " ";
            }
            for (int i = 0; i < mp[n][k].second; ++i) {
                cout << -1 << " ";
            }
            cout << "\n";
        }
    }
}
