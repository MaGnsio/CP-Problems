/**
 *    author:  MaGnsi0
 *    created: 05/10/2021 02:29:35
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        vector<int> deg(n, 0);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            deg[u - 1]++, deg[v - 1]++;
        }
        if (deg[x - 1] <= 1) {
            cout << "Ayush\n";
        } else {
            cout << (n & 1 ? "Ashish\n" : "Ayush\n");
        }
    }
}
