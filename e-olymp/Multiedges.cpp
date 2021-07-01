//https://www.e-olymp.com/en/contests/15927/problems/164105
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> V(N, vector<int>(N, 0));
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        V[x - 1][y - 1]++;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (V[i][j] > 1) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
}

