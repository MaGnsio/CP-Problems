/**
 *    author:  MaGnsi0
 *    created: 01.07.2023 14:09:22
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
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        function<bool(int, int)> alone = [&](int i, int j) {
            if (i && a[i - 1][j] == a[i][j]) {
                return false;
            }
            if (i + 1 < n && a[i + 1][j] == a[i][j]) {
                return false;
            }
            return true;
        };
        int ans =  0;
        vector<vector<bool>> visited(n, vector<bool>(2, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (visited[i][j]) { continue; }
                if (alone(i, j)) { continue; }
                int cur_length = 0, k = i;
                vector<int> segments;
                while (k < n && a[k][j] == a[i][j]) {
                    if (a[k][j ^ 1] == a[k][j] && alone(k, j ^ 1)) {
                        if (cur_length) { segments.push_back(cur_length); }
                        visited[k][j ^ 1] = true;
                        cur_length = 0;
                    } else {
                        cur_length++;
                    }
                    visited[k][j] = true, k++;
                }
                if (cur_length) {
                    segments.push_back(cur_length);
                }
                for (int x = 0; x < (int)segments.size(); ++x) {
                    if (segments[x] == 1) {
                        ans++;
                        if (x + 1 < (int)segments.size()) {
                            segments[x + 1] += 2;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (visited[i][0] == false && visited[i][1] == false && a[i][0] == a[i][1]) {
                continue;
            }
            for (int j = 0; j < 2; ++j) {
                ans += visited[i][j] == false && alone(i, j);
            }
        }
        cout << ans << "\n";
    }
}
