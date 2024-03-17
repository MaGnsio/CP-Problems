/**
 *    author:  MaGnsi0
 *    created: 02.12.2023 14:49:12
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int Q; cin >> Q;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> b(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i][j] = a[i][j] == 'B';
        }
        for (int j = 1; j < n; ++j) {
            b[i][j] += b[i][j - 1];
        }
    }
    while (Q--) {
        int Xlow; cin >> Xlow;
        int Ylow; cin >> Ylow;
        int Xhigh; cin >> Xhigh;
        int Yhigh; cin >> Yhigh;
        int64_t ans = 0;
        vector<int64_t> rowCount(n);
        for (int row = 0; row < n; ++row) {
            int64_t low = Xlow % n;
            int64_t high = (Xlow + (n - low - 1) <= Xhigh ? n - 1 : Xhigh % n);
            int64_t newS = Xhigh - (Xlow + (high - low + 1)) + 1;
            rowCount[row] = (low <= row && row <= high) + (newS != 0) * (newS / n) + (newS != 0) * (newS % n > row); 
        }
        for (int row = 0; row < n; ++row) {
            int64_t low = Ylow % n;
            int64_t high = (Ylow + (n - low - 1) <= Yhigh ? n - 1 : Yhigh % n);
            int64_t newS = Yhigh - (Ylow + (high - low + 1)) + 1;
            ans += rowCount[row] * ((b[row][high] - (low ? b[row][low - 1] : 0)) + ((newS / n) * b[row][n - 1]) + ((newS % n ? b[row][newS % n - 1] : 0)));
        }
        cout << ans << "\n";
    }
}
