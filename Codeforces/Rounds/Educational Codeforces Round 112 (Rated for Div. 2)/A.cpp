/**
 *    author:  MaGnsi0
 *    created: 22/08/2021 19:07:55
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        long long k = (5 * n + 1LL) / 2;
        while (k % 5 != 0 || k < 15) {
            k++;
        }
        cout << k << "\n";
    }
}
