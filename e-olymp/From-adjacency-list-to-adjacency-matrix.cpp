//https://www.e-olymp.com/en/contests/15927/problems/164100
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N;
    cin >> N;
    vector<vector<int>> V(N, vector<int>(N, 0));
    for (int i = 0, M; i < N; ++i) {
        cin >> M;
        for (int j = 0, x; j < M; ++j) {
            cin >> x;
            V[i][x - 1] = 1;
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << V[i][j] << " ";
        }
        cout << "\n";
    }
}

