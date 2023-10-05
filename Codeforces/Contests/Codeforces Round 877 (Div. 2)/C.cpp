/**
 *    author:  MaGnsi0
 *    created: 04.06.2023 18:12:26
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<bool> is_prime(N, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < N; ++i) {
        if (is_prime[i]) {
            for (int j = 2 * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        if (is_prime[m] == false) {
            for (int i = 0, x = 1; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << x++ << " ";
                }
                cout << "\n";
            }
        } else if (is_prime[n] == false) {
            vector<vector<int>> a(n, vector<int>(m));
            for (int j = 0, x = 1; j < m; ++j) {
                for (int i = 0; i < n; ++i) {
                    a[i][j] = x++;
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << a[i][j] << " ";
                }
                cout << "\n";
            }
        } else {
            int x = n * m;
            vector<vector<int>> a(n, vector<int>(m));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    a[i][j] = x--;
                }
                if (x) { x -= m; }
                if (x == 0) { x = n * m - m; }
            }
            if (is_prime[abs(a[n - 1][m - 1] - a[n - 2][m - 1])]) {
                reverse(a[n - 1].begin(), a[n - 1].end());
                for (int i = 1; i < m; i += 2) {
                    swap(a[n - 1][i], a[n - 1][i + 1]);
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << a[i][j] << " ";
                }
                cout << "\n";
            }
        }
    }
}
