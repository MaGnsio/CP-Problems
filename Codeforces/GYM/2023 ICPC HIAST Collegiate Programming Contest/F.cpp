/**
 *    author:  MaGnsi0
 *    created: 27.08.2023 15:04:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j]; a[i][j]--;
        }
    }
    for (int i = 0; i < n; ++i) {
        vector<bool> visited(n, false);
        for (int j = 0; j < n; ++j) {
            if (visited[a[i][j]]) {
                cout << "NO";
                return 0;
            }
            visited[a[i][j]] = true;
        }
    }
    for (int j = 0; j < n; ++j) {
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (visited[a[i][j]]) {
                cout << "NO";
                return 0;
            }
            visited[a[i][j]] = true;
        }
    }
    cout << "YES";
}
