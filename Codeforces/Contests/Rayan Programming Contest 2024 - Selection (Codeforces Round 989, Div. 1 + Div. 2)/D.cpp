/**
 *    author:  MaGnsi0
 *    created: 30.11.2024 16:50:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; b[i] = a[i];
        }
        sort(b.begin(), b.end());
        vector<set<int>> pos(3);
        for (int i = 0; i < n; ++i) {
            pos[a[i]].insert(i);
        }
        vector<pair<int, int>> ops;
        function<void(int, int)> do_op = [&](int i, int j) {
            pos[a[i]].erase(i);
            pos[a[j]].erase(j);
            swap(a[i], a[j]);
            pos[a[i]].insert(i);
            pos[a[j]].insert(j);
            ops.emplace_back(i + 1, j + 1);
        };
        for (int i = 0; i < n; ++i) {
            //a[i] == 0 b[i] == 1 => won't happen
            //a[i] == 0 b[i] == 2 => won't happen
            //a[i] == 1 b[i] == 0 => get last occuring 0 and do op
            //a[i] == 1 b[i] == 2 => won't happen
            //a[i] == 2 b[i] == 0 => get last occuring 1 and do op and repeat
            //a[i] == 2 b[i] == 1 => get last occuring 1 and do op
            if (a[i] == b[i]) { continue; }
            assert(!(a[i] == 0 && b[i] == 1) && !(a[i] == 1 && b[i] == 2) && !(a[i] == 1 && b[i] == 2));
            if (a[i] == 1 && b[i] == 0) {
                int j = *pos[0].rbegin();
                do_op(i, j);
            } else if (a[i] == 2 && b[i] == 0) {
                int j = *pos[1].rbegin();
                do_op(i, j); i--;
            } else if (a[i] == 2 && b[i] == 1) {
                int j = *pos[1].rbegin();
                do_op(i, j);
            }
        }
        assert(a == b);
        assert((int)ops.size() <= n);
        cout << (int)ops.size() << "\n";
        for (auto [i, j] : ops) {
            cout << i << " " << j << "\n";
        }
    }
}
