/**
 *    author:  MaGnsi0
 *    created: 19.11.2021 01:32:08
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
        vector<vector<int>> a(n, vector<int>(n, 0));
        int dy = 0;
        while (k) {
            for (int i = 0; i < n; ++i) {
                if (k) {
                    a[i][(i + dy) % n] = 1;
                    k--;
                }
            }
            dy++;
        }
        int maxR = 0, minR = n, maxC = 0, minC = n;
        for (int i = 0; i < n; ++i) {
            int sumR = 0, sumC = 0;
            for (int j = 0; j < n; ++j) {
                sumR += a[i][j];
                sumC += a[j][i];
            }
            maxR = max(maxR, sumR);
            minR = min(minR, sumR);
            maxC = max(maxC, sumC);
            minC = min(minC, sumC);
        }
        int Rs = (maxR - minR) * (maxR - minR);
        int Cs = (maxC - minC) * (maxC - minC);
        int f = (Rs + Cs);
        cout << f << "\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << a[i][j];
            }
            cout << "\n";
        }
    }
}
