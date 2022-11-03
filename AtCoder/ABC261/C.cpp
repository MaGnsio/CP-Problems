/**
 *    author:  MaGnsi0
 *    created: 25.07.2022 08:37:13
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
    map<string, int> F;
    for (int i = 0; i < N; ++i) {
        cout << A[i];
        if (F[A[i]]++) {
            cout << "(" << F[A[i]] - 1 << ")";
        }
        cout << "\n";
    }
}
