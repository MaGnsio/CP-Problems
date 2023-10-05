/**
 *    author:  MaGnsi0
 *    created: 18/08/2021 16:27:49
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    vector<int> f;
    for (int i = 1; i <= 1000000; ++i) {
        if (i % 3 == 0 || i % 10 == 3) {
            continue;
        }
        f.push_back(i);
    }
    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;
        cout << f[k - 1] << "\n";
    }
}
