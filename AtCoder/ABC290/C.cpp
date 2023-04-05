/**
 *    author:  MaGnsi0
 *    created: 19.02.2023 14:04:59
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    set<int> s(a.begin(), a.end());
    int mex = 0;
    for (int i = 0; i < k; ++i) {
        if (s.count(mex)) {
            mex++;
        } else {
            break;
        }
    }
    cout << mex;
}
