/**
 *    author:  MaGnsi0
 *    created: 05.02.2023 14:07:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int turn = 1, j = 2;
        vector<int> a(2);
        a[0] = 1;
        n--;
        while (n) {
            a[turn] += min(j, n);
            n -= min(n, j);
            j++;
            a[turn] += min(j, n);
            n -= min(n, j);
            j++;
            turn ^= 1;
        }
        cout << a[0] << " " << a[1] << "\n";
    }
}
