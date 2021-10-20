/**
 *    author:  MaGnsi0
 *    created: 16/07/2021 13:24:44
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }
    sort(v.begin(), v.end());
    for (int i = 0, cur = 1; i < n; ++i) {
        if (v[i] >= cur) {
            v[i] = cur;
            cur++;
        }
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] != i + 1) {
            cout << i + 1;
            return 0;
        }
    }
    cout << *max_element(v.begin(), v.end()) + 1;
}
