/**
 *    author:  MaGnsi0
 *    created: 18/09/2021 16:32:01
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        int dec = 0, swaps = 0;
        for (int i = 0; i < n; ++i) {
            dec += (s[i] - '0');
            swaps += (s[i] != '0' && i != n - 1);
        }
        cout << dec + swaps << "\n";
    }
}
