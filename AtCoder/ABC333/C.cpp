/**
 *    author:  MaGnsi0
 *    created: 16.12.2023 14:03:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N = 12;
    vector<int64_t> repunits(N);
    for (int i = 0; i < N; ++i) {
        repunits[i] = stoll(string(i + 1, '1'));
    }
    vector<int64_t> sums;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                sums.push_back(repunits[i] + repunits[j] + repunits[k]);
            }
        }
    }
    sort(sums.begin(), sums.end());
    sums.resize(unique(sums.begin(), sums.end()) - sums.begin());
    int n; cin >> n; cout << sums[n - 1];
}
