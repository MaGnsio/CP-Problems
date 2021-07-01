//https://www.e-olymp.com/en/contests/15927/problems/164096
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, BB = 0;
    cin >> N;
    vector<vector<int>> V(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> V[i][j];
        }
    }
    vector<int> C(N);
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            BB += (V[i][j] && C[i] != C[j]);
        }
    }
    cout << BB;
}

