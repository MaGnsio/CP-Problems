/**
 *    author:  MaGnsi0
 *    created: 27.07.2023 06:26:28
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int64_t> ans(N);
    for (int64_t i = 1; i < N; ++i) {
        for (int64_t j = i; i + j < N; j += i) {
            ans[i + j] += j / i;
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << ans[n] << "\n";
    }
}
