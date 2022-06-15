/**
 *    author:  MaGnsi0
 *    created: 09.04.2022 03:18:27
**/
#include <bits/stdc++.h>
using namespace std;

const long long N = 1e6;

void WORK() {
    int N;
    cin >> N;
    vector<int> A(2 * N);
    for (int i = 0; i < 30; ++i) {
        A[i] = (1LL << i);
    }
    for (int i = 30; i < N; ++i) {
        A[i] = (int)1e9 - (N - i - 1);
    }
    for (int i = 0; i < N; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < N; ++i) {
        cin >> A[N + i];
    }
    int64_t S = accumulate(A.begin(), A.end(), 0LL) / 2;
    vector<int> res;
    for (int i = 2 * N - 1; S >= (1LL << 30); --i) {
        if (S >= A[i]) {
            res.push_back(A[i]);
            S -= A[i];
        }
    }
    for (int i = 0; i < 30; ++i) {
        if (A[i] & S) {
            res.push_back(A[i]);
        }
    }
    for (int i = 0; i < (int)res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        WORK();
    }
}
