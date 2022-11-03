//https://atcoder.jp/contests/abc200/tasks/abc200_d
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, A = -1;
    cin >> N;
    vector<int> V(N);
    vector<vector<vector<int>>> X(200);
    for (int i = 0; i < N; ++i) {
        cin >> V[i];
    }
    for (int mask = 1; mask < (1 << min(N, 8)); ++mask) {
        int a = 0;
        vector<int> x;
        for (int j = 0; j < min(N, 8); ++j) {
            if ((1 << j) & mask) {
                a = (a + V[j]) % 200;
                x.push_back(j + 1);
            }
        }
        X[a].push_back(x);
        if (X[a].size() == 2) {
            A = a;
            break;
        }
    }
    if (A == -1) {
        cout << "No";
    } else {
        cout << "Yes";
        cout << "\n" << X[A][0].size() << " ";
        for (int i = 0; i < X[A][0].size(); ++i) {
            cout << X[A][0][i] << " ";
        }
        cout << "\n" << X[A][1].size() << " ";
        for (int i = 0; i < X[A][1].size(); ++i) {
            cout << X[A][1][i] << " ";
        }
    }
}
