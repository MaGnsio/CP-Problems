/**
 *    author:  MaGnsi0
 *    created: 28.11.2021 16:27:40
**/
#include <bits/stdc++.h>

using namespace std;

int N = 1e6 + 6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<bool> isP(N, true);
    {
        isP[0] = isP[1] = false;
        for (int i = 2; i < N; ++i) {
            if (isP[i]) {
                for (int j = 2 * i; j < N; j += i) {
                    isP[j] = false;
                }
            }
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n, e;
        cin >> n >> e;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        long long res = 0;
        vector<int> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                continue;
            }
            if (a[i] == 1 || isP[a[i]]) {
                vector<int> temp;
                if (isP[a[i]]) {
                    temp.push_back(-1);
                } else {
                    temp.push_back(1);
                }
                visited[i] = true;
                for (int j = i + e; j < n; j += e) {
                    if (a[j] == 1) {
                        if (temp.back() == -1) {
                            temp.push_back(1);
                        } else {
                            temp.back()++;
                        }
                        visited[j] = true;
                    } else if (isP[a[j]]) {
                        temp.push_back(-1);
                        visited[j] = true;
                    } else {
                        break;
                    }
                }
                int m = temp.size();
                for (int j = 0; j < (int)temp.size(); ++j) {
                    if (temp[j] == -1) {
                        if (j + 1 < m && temp[j + 1] != -1) {
                            res += temp[j + 1];
                        }
                        if (j - 1 >= 0 && temp[j - 1] != -1) {
                            res += temp[j - 1];
                        }
                        if (j + 1 < m && temp[j + 1] != -1 && j - 1 >= 0 && temp[j - 1] != -1) {
                            res += (1LL * temp[j - 1] * temp[j + 1]);
                        }
                    }
                }
            }
        }
        cout << res << "\n";
    }
}
