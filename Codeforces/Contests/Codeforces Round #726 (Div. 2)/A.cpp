/**
 *    author:  MaGnsi0
 *    created: 18/06/2021 16:27:03
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
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            sum += x;
        }
        cout << (sum - n < 0 ? 1 : sum - n) << "\n";
    }
}
