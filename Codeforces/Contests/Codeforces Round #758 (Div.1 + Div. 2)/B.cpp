/**
 *    author:  MaGnsi0
 *    created: 13.12.2021 15:41:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> A(n, -1);
        if (abs(a - b) > 1) {
            cout << -1 << "\n";
            continue;
        }
        if (a + b + 2 > n) {
            cout << -1 << "\n";
            continue;
        }
        if (!a && !b) {
            for (int i = 0; i < n; ++i) {
                cout << i + 1 << " ";
            }
        } else if (a >= b) {
            int x = 1;
            A[0] = x++;
            for (int i = 2, j = 0; i < n && j < a; i += 2, ++j) {
                A[i] = x++;
            }
            x = n;
            for (int i = 1, j = 0; i < n && j < a; i += 2, ++j) {
                A[i] = x--;
                if (j == a - 1) {
                    for (int k = i + 2; k < n; ++k) {
                        A[k] = x--;
                    }
                    sort(A.begin() + i + 1, A.end(), greater<int>());
                    if (a == b) {
                        swap(A[n - 1], A[n - 2]);
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                cout << A[i] << " ";
            }
        } else {
            int x = n;
            A[0] = x--;
            for (int i = 2, j = 0; i < n && j < b; i += 2, ++j) {
                A[i] = x--;
            }
            x = 1;
            for (int i = 1, j = 0; i < n && j < b; i += 2, ++j) {
                A[i] = x++;
                if (j == b - 1) {
                    for (int k = i + 2; k < n; ++k) {
                        A[k] = x++;
                    }
                    sort(A.begin() + i + 1, A.end());
                    if (a == b) {
                        swap(A[n - 1], A[n - 2]);
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                cout << A[i] << " ";
            }
        }
        cout << "\n";
    }
}
