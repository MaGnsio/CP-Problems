/**
 *    author:  MaGnsi0
 *    created: 13.03.2023 23:26:38
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }
    set<int> called;
    for (int i = 0; i < n; ++i) {
        if (called.count(i) == 0) {
            called.insert(a[i]);
        }
    }
    int m = 0;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (called.count(i) == 0) {
            ans.push_back(i + 1);
            m++;
        }
    }
    cout << m << "\n";
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << " ";
    }
}
