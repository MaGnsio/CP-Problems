/**
 *    author:  MaGnsi0
 *    created: 13.09.2023 18:42:31
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 1e6 + 6;

int G(int x) {
    int ans = 0;
    while (x) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int64_t> F(N);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; F[x]++;
    }
    for (int i = N - 1; i > 0; --i) {
        F[i - G(i)] += F[i];
    }
    for (int i = N - 2; i >= 0; --i) {
        F[i] += F[i + 1];
    }
    int ans = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (F[i] >= k) {
            ans = G(i);
            break;
        }
    }
    cout << ans;
}
