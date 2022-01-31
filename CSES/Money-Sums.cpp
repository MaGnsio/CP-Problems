/**
 *    author:  MaGnsi0
 *    created: 05.01.2022 20:40:58
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<bool> dp(N, false);
    dp[0] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = N - 1; j >= a[i]; --j) {
            dp[j] = (dp[j] | dp[j - a[i]]);
        }
    }
    vector<int> sums;
    for (int i = 1; i < N; ++i) {
        if (dp[i]) {
            sums.push_back(i);
        }
    }
    cout << sums.size() << "\n";
    for (int i = 0; i < (int)sums.size(); ++i) {
        cout << sums[i] << " ";
    }
}
