/**
 *    author:  MaGnsi0
 *    created: 18.06.2022 14:29:17
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> L(n), R(n), F(N, 0);
    for (int i = 0; i < n; ++i) {
        cin >> L[i] >> R[i];
        F[L[i]]++;
        F[R[i]]--;
    }
    for (int i = 1; i < N; ++i) {
        F[i] += F[i - 1];
    }
    vector<int> ansL, ansR;
    for (int i = 1; i + 1 < N; ++i) {
        if (F[i] && F[i - 1] == 0) {
            ansL.push_back(i);
        }
        if (F[i] && F[i + 1] == 0) {
            ansR.push_back(i);
        }
    }
    assert((int)ansL.size() == (int)ansR.size());
    for (int i = 0; i < (int)ansL.size(); ++i) {
        cout << ansL[i] << " " << ansR[i] + 1 << "\n";
    }
}
