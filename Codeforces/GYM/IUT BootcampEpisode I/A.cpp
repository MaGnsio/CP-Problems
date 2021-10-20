/**
 *    author:  MaGnsi0
 *    created: 12/07/2021 03:53:31
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        //n is even -> each hour both cats're in different spot (different parity).
        //n is odd -> each floor(n / 2) hour cats meet and a is shifted by one.
        cout << (k - 1 + (k - 1) / (n / 2) * (n % 2)) % n + 1 << "\n";
    }
}
