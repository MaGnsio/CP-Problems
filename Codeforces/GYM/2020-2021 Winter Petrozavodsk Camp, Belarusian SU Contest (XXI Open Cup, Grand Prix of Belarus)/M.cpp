/**
 *    author:  MaGnsi0
 *    created: 23.09.2023 13:13:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, m = 1, k1 = 1, k2 = 1;
    cin >> n;
    vector<int64_t> ans(1, 1);
    while (9 * m * m < 4 * n) {
        int64_t next_k = k2 + 1;
        while (__gcd(next_k, k1) != 1) { next_k++; }
        k1 = k2, k2 = next_k;
        ans.push_back(k1 * k2);
        m++;
    }
    cout << m << "\n";
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << " ";
    }
}
