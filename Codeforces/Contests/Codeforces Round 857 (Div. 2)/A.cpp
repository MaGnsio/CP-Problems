/**
 *    author:  MaGnsi0
 *    created: 02.01.2024 18:36:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int pos = 0, neg = 0;
        for (int i = 0; i < n; ++i) {
            pos += a[i] > 0;
            neg += a[i] < 0;
        }
        for (int i = 0; i < n; ++i) {
            int likes = min(i + 1, pos);
            int dislikes = max(0, i + 1 - pos);
            cout << likes - dislikes << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; ++i) {
            int dislikes = min((i + 1) / 2, neg);
            int likes = i + 1 - dislikes;
            cout << likes - dislikes << " ";
        }
        cout << "\n";
    }
}
