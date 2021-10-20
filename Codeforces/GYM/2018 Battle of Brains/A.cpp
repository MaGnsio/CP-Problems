/**
 *    author:  MaGnsi0
 *    created: 17/08/2021 18:21:49
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, sum = 0;
        cin >> n;
        for (int i = 0, x; i < 4; ++i) {
            cin >> x;
            sum += x;
        }
        cout << (n + 1 <= 2 * sum ? "Yes\n" : "No\n");
    }
}
