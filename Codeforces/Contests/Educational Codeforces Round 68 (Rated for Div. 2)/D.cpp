/**
 *    author:  MaGnsi0
 *    created: 26.09.2022 18:43:35
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        if (k % 3) {
            cout << (n % 3 ? "Alice" : "Bob") << "\n";
        } else {
            int pos = n % (k + 1);
            cout << ((n < k && n % 3) || (pos % 3 || pos == k) ? "Alice" : "Bob") << "\n";
        }
    }
}
