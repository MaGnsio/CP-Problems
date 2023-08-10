/**
 *    author:  MaGnsi0
 *    created: 07.07.2023 02:16:53
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
        if (n % 3 == 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            vector<int> ans(n - 1), a, b;
            ans[0] = 1;
            int u = 4;
            while (u != 1) {
                a.push_back(u);
                u += 3;
                if (u > n) { u = u - n; }
            }
            u = n - 2;
            while (u != 1) {
                b.push_back(u);
                u -= 3;
                if (u < 1) { u = u + n; }
            }
            for (int i = 1, j = 0, k = 0; i < n - 1; ++i) {
                if (j < (int)a.size() && k < (int)b.size()) {
                    if (a[j] < b[k]) {
                        ans[i] = a[j++]; 
                    } else {
                        ans[i] = b[k++];
                    }
                } else if (j < (int)a.size()) {
                    ans[i] = a[j++];
                } else {
                    ans[i] = b[k++];
                }
            }
            for (int i = 0; i < n - 1; ++i) {
                cout << ans[i] << " ";
            }
            cout << "\n";
        }
    }
}
