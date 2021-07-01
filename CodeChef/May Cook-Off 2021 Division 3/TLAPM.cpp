//https://www.codechef.com/COOK129C/problems/TLAPM
#include <bits/stdc++.h>
using namespace std;
const int maxN = 1001;

void Fill(vector<vector<int>>& G) {
    for (int j = 1, x = 2, s = 1; j < maxN; ++j, ++x) {
        for (int i = 1, y = x - 1; i < maxN; ++i, ++y) {
            if (i == 1) {
                G[i][j] = s;
            } else {
                G[i][j] = G[i - 1][j] + y;
            }
        }
        s += (x - 1);
    }
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    vector<vector<int>> G(maxN, vector<int>(maxN, 0));
    Fill(G);
    int T;
    cin >> T;
    while (T--) {
        int X1, Y1, X2, Y2, maxi = 0;
        cin >> X1 >> Y1 >> X2 >> Y2;
        for (int i = X1; i < X2; ++i) {
            maxi += G[i][Y1];
        }
        for (int i = Y1; i <= Y2; ++i) {
            maxi += G[X2][i];
        }
        cout << maxi << "\n";
    }
}
