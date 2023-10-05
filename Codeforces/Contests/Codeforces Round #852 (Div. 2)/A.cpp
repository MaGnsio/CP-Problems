/**
 *    author:  MaGnsi0
 *    created: 12.02.2023 10:36:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t a, b;
        cin >> a >> b;
        int64_t n, m;
        cin >> n >> m;
        int64_t x = n / (m + 1);
        int64_t ans1 = a * (x * m + n % (m + 1));
        int64_t ans2 = (a * x * m + b * (n % (m + 1)));
        int64_t ans3 = n * b;
        cout << min({ans1, ans2, ans3}) << "\n";
    }
}
