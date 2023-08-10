/**
 *    author:  MaGnsi0
 *    created: 25.02.2023 15:44:11
**/
#include <bits/stdc++.h>

using namespace std;

int64_t sum(int64_t n) {
    return n * (n + 1) / 2;
}

int64_t F(int64_t n) {
    if (n == 0) { return 0; }
    int64_t ans = 0, i = 1;
    while(true) {
        ans += i * (sum(n / i) - sum(n / (i + 1)));
        if (i == n) { break; }
        i = n / (n / (i + 1));
    }
    return ans;
}  

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t l, r;
    cin >> l >> r;
    cout << F(r) - F(l - 1);
}
