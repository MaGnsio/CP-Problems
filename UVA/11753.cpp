/**
 *    author:  MaGnsi0
 *    created: 20/09/2021 23:24:38
**/
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> v;

int dp(int i, int j, int curk) {
    if (curk > k || i >= j) {
        return curk;
    }
    if (v[i] == v[j]) {
        return dp(i + 1, j - 1, curk);
    } else {
        return min(dp(i + 1, j, curk + 1), dp(i, j - 1, curk + 1));
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> n >> k;
        v = vector<int>(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        int res = dp(0, n - 1, 0);
        cout << "Case " << t << ": ";
        if (res == 0) {
            cout << "Too easy\n";
        } else if (res <= k) {
            cout << res << "\n";
        } else {
            cout << "Too difficult\n";
        }
    }
}

/* EDITORIAL :-
 *
 * as (1 <= n <= 10000) we can't do normal O(n^2) longest palindromic subsequence algorithm.
 * so we have to take advantage of small k (1 <= k <= 20)
 * if we go normal recursion without memoization with state (i, j, curk)
 * : i(starting index), j(ending index), (curk)number of insertions made so far.
 * we can't go no more than max(n, 2^k) different states wich is an acceptable complexity.
 */
