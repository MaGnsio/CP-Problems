//https://www.e-olymp.com/en/contests/15927/problems/164112
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
    vector<int> A, B;
    for (int i = 0; i < N; ++i) {
        int cnt = 0;
        for (int j = 0; j < N; ++j) {
            cnt += V[i][j];
        }
        if (!cnt) {
            A.push_back(i + 1);
        }
    }
    for (int i = 0; i < N; ++i) {
        int cnt = 0;
        for (int j = 0; j < N; ++j) {
            cnt += V[j][i];
        }
        if (!cnt) {
            B.push_back(i + 1);
        }
    }
    cout << B.size();
    for (auto& x : B) {
        cout << " " << x;
    }
    cout << "\n" << A.size();
    for (auto& x : A) {
        cout << " " << x;
    }
}

