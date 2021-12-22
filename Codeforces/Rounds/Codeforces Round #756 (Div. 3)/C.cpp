/**
 *    author:  MaGnsi0
 *    created: 25.11.2021 16:25:42
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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (a[0] != n && a[n - 1] != n) {
            cout << "-1\n";
            continue;
        }
        if (n == 2) {
            for (int i = 0; i < n; ++i) {
                cout << a[i] << " ";
            }
            cout << "\n";
            continue;
        }
        int i = 0, j = n - 1;
        deque<int> q;
        if (a[i] == n) {
            q.push_back(a[i++]);
        } else {
            q.push_back(a[j--]);
        }
        while (j - i >= 1) {
            if (j - i == 1) {
                q.push_front(a[i]);
                q.push_back(a[j]);
                break;
            }
            if (a[i] < a[j]) {
                q.push_front(a[i++]);
            } else {
                q.push_back(a[j--]);
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << q[i] << " ";
        }
        cout << "\n";
    }
}
