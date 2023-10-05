/**
 *    author:  MaGnsi0
 *    created: 06.04.2023 16:36:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, s1, s2;
        cin >> n >> s1 >> s2;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            b[i] = i;
        }
        sort(b.begin(), b.end(), [&](int i, int j) {
                return a[i] > a[j];
            });
        int m1 = 0, m2 = 0;
        vector<int> ans1, ans2;
        for (int i = 0; i < n; ++i) {
            int j = b[i];
            int t1 = (m1 + 1) * s1;
            int t2 = (m2 + 1) * s2;
            if (t1 < t2) {
                ans1.push_back(j + 1);
                m1++;
            } else {
                ans2.push_back(j + 1);
                m2++;
            }
        }
        cout << m1 << " ";
        for (int i = 0; i < m1; ++i) {
            cout << ans1[i] << " ";
        }
        cout << "\n";
        cout << m2 << " ";
        for (int i = 0; i < m2; ++i) {
            cout << ans2[i] << " ";
        }
        cout << "\n";
    }
}
