/**
 *    author:  MaGnsi0
 *    created: 05.05.2024 14:29:15
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 3;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> X, Y;
    X.push_back(1), Y.push_back(1);
    X.push_back(1), Y.push_back(2);
    for (int i = 3; i < N; ++i) {
        X.push_back(i);
        Y.push_back(i);
    }
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        for (int i = 0; i < n; ++i) {
            cout << X[i] << " " << Y[i] << "\n";
        }
    }
}
