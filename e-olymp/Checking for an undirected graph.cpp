//https://www.e-olymp.com/en/contests/15927/problems/164102
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N;
    cin >> N;
    vector<vector<int>> V(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> V[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (V[i][j] != V[j][i] || (i == j && V[i][j])) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}

