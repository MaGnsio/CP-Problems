/**
 *    author:  MaGnsi0
 *    created: 26.08.2023 17:48:39
**/
#include <bits/stdc++.h>

using namespace std;

int F(int x) {
    for (int i = 0; i < 30; ++i) {
        if (x >> i & 1) {
            return i;
        }
    }
    assert(0);
    return -1;
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int x;
        cin >> x;
        vector<int> ans;
        while (x & (x - 1)) {
            ans.push_back(x);
            x -= 1 << F(x);
        }
        while (x != 1) {
            ans.push_back(x);
            x -= x / 2;
        }
        ans.push_back(x);
        int k = (int)ans.size();
        cout << k << "\n";
        for (int i = 0; i < k; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
