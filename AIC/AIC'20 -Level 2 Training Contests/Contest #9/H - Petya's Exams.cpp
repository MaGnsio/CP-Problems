//https://vjudge.net/contest/435043#problem/H
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, M, cnt = 0;
    cin >> N >> M;
    vector<int> V(N + 1, 0);
    vector<vector<int>> A(M, vector<int>(4));
    for (int i = 0; i < M; ++i) {
        cin >> A[i][1] >> A[i][0] >> A[i][2];
        A[i][3] = i + 1;
    }
    sort(A.begin(), A.end());
    for (int j = 0; j < M; ++j) {
        for (int i = 1; i <= N && A[j][2] != 0; ++i) {
            if (i < A[j][1] || i >= A[j][0] || V[i] != 0) {
                continue;
            }
            V[i] = A[j][3];
            A[j][2]--;
        }
        if (A[j][2] == 0) {
            V[A[j][0]] = M + 1;
            cnt++;
        }
    }
    if (cnt != M) {
        cout << -1;
    } else {
        for (int i = 1; i <= N; ++i) {
            cout << V[i] << " ";
        }
    }
}

