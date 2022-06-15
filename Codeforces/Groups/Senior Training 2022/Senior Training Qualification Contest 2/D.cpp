/**
 *    author:  MaGnsi0
 *    created: 12.03.2022 19:02:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("math.in", "r", stdin);
    long long n;
    cin >> n;
    long long ans = 1;
    for (int i = 0; ; ++i) {
        if ((1LL << i) <= n) {
            ans = (1LL << i);
        } else {
            break;
        }
    }
    cout << ans;
}
