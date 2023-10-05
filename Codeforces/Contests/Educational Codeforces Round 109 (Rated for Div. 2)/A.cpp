//https://codeforces.com/contest/1525/problem/A
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;
        cout << 100 / gcd(k, 100 - k) << "\n";
    }
}
