/**
 *    author:  MaGnsi0
 *    created: 23/07/2021 16:29:39
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << n / 3 + (n % 3 == 1) << " " << n / 3 + (n % 3 == 2) << "\n";
    }
}
