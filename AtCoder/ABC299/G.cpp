/**
 *    author:  MaGnsi0
 *    created: 22.04.2023 14:54:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }
    vector<int> b(m);
    for (int i = 0; i < n; ++i) {
        b[a[i]]++;
    }
    vector<int> ans;
    vector<bool> done(m, false);
    for (int i = 0; i < n; ++i) {
        if (done[a[i]] == false) {
            while (!ans.empty() && ans.back() > a[i] && b[ans.back()]) {
                done[ans.back()] = false;
                ans.pop_back();
            }
            ans.push_back(a[i]);
            done[a[i]] = true;
        }
        b[a[i]]--;
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[i] + 1 << " ";
    }
}
