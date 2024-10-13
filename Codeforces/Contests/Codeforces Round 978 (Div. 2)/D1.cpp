/**
 *    author:  MaGnsi0
 *    created: 13.10.2024 23:34:29
**/
#include <bits/stdc++.h>

using namespace std;

int F(int i, int j) {
    cout << "? " << i + 1 << " " << j + 1 << endl;
    int x; cin >> x; return x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        array<int, 2> candidate_imposters = {-1, -1};
        for (int i = 1; i < n; i += 2) {
            if (F(i - 1, i) != F(i, i - 1)) {
                candidate_imposters[0] = i - 1;
                candidate_imposters[1] = i;
            }
        }
        if (candidate_imposters[0] == -1) {
            cout << "! " << n << endl;
            continue;
        }
        int decider = (candidate_imposters[0] == 0 ? n - 1 : 0);
        bool f1 = F(candidate_imposters[0], decider) != F(decider, candidate_imposters[0]);
        bool f2 = F(candidate_imposters[1], decider) != F(decider, candidate_imposters[1]);
        assert(f1 ^ f2);
        cout << "! " << (f1 ? candidate_imposters[0] : candidate_imposters[1]) + 1 << endl;
    }
}
