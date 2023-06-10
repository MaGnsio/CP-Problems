/**
 *    author:  MaGnsi0
 *    created: 04.06.2023 00:44:16
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 303 * 303;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    vector<bitset<N>> dp(n, 0);
    dp[0][0] = dp[0][a[0]] = 1;
    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i - 1] | (dp[i - 1] << a[i]);
    }
    if ((sum & 1) || (dp[n - 1][sum / 2] == 0)) {
        cout << "First" << endl;
        while (true) {
            int x, y;
            for (int i = 0; i < n; ++i) {
                if (a[i] > 0) { x = i; }
            }
            cout << x + 1 << endl;
            cin >> y;
            if (y <= 0) { return 0; }
            int d = min(a[x], a[y - 1]);
            a[x] -= d, a[y - 1] -= d;
        }
    } else {
        cout << "Second" << endl;
        vector<int> group(n, 0);
        int j = n - 1, cur_sum = sum / 2;
        while (cur_sum) {
            assert(dp[j][cur_sum] == 1);
            if (cur_sum == a[j]) {
                group[j] = 1;
                cur_sum -= a[j];
            } else if (cur_sum > a[j] && dp[j - 1][cur_sum - a[j]]) {
                group[j] = 1;
                cur_sum -= a[j];
            }
            j--;
        }
        while (true) {
            int x, y;
            cin >> x;
            if (x <= 0) { return 0; }
            for (int i = 0; i < n; ++i) {
                if (a[i] > 0 && group[i] != group[x - 1]) { y = i; }
            }
            cout << y + 1 << endl;
            int d = min(a[x - 1], a[y]);
            a[x - 1] -= d, a[y] -= d;
        }
    }
}
