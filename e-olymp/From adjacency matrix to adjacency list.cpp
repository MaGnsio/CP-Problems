//https://www.e-olymp.com/en/contests/15927/problems/164099
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N;
    cin >> N;
    vector<vector<int>> V(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int x;
            cin >> x;
            if (x) {
                V[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << V[i].size();
        for (int j = 0; j < V[i].size(); ++j) {
            cout << " " << V[i][j] + 1;
        }
        cout << "\n";
    }
}

