/**
 *    author:  MaGnsi0
 *    created: 17.04.2023 22:01:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, m, k;
    cin >> n >> m >> k;
    int64_t ans = min(n, k / m);
    cout << ans << "\n";
}
