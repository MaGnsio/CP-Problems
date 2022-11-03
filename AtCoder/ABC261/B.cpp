/**
 *    author:  MaGnsi0
 *    created: 25.07.2022 08:32:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<string> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    bool correct = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            correct &= ((i == j) || (A[i][j] == 'D' && A[j][i] == 'D') || (A[i][j] == 'W' && A[j][i] == 'L') || (A[i][j] == 'L' && A[j][i] == 'W'));
        }
    }
    cout << (correct ? "correct" : "incorrect");
}
