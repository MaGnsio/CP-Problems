/**
 *    author:  MaGnsi0
 *    created: 12.10.2025 03:53:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> K, X;
        function<int(int)> get_permutation = [&](int i) {
            if (a[i] == 1) {
                for (int j = i + 1; j < n; ++j) {
                    if (a[j] - a[j - 1] != 1) {
                        K.push_back(j - i); X.push_back(a[i] - 1);
                        return j;
                    }
                }
                K.push_back(n - i); X.push_back(0);
                return n;
            }
            int o = -1;
            for (int j = i; j < n; ++j) {
                if (a[j] == 1) { o = j; break; }
            }
            assert(o != -1);
            for (int j = o; j < n; ++j) {
                if (a[i] == a[j] + 1) {
                    K.push_back(j - i + 1); X.push_back(a[i] - 1);
                    return j + 1;
                }
            }
            assert(0);
            return -1;
        };
        for (int i = 0; i < n; /*_*/) {
            i = get_permutation(i);
        }
        int m = (int)K.size(), ops = m;
        vector<int> op2(m);
        for (int i = m - 1; i >= 0; --i) {
            int done = (ops - m) % K[i];
            int need = X[i];
            if (done <= need) {
                op2[i] = need - done;
            } else {
                op2[i] = K[i] - (done - need);
            }
            ops += op2[i];
        }
        assert(ops <= 2 * n);
        cout << ops << "\n";
        for (int i = 0; i < m; ++i) {
            cout << "1 " << K[i] << "\n";
            for (int j = 0; j < op2[i]; ++j) {
                cout << "2\n";
            }
        }
    }
}
// We can know:
//   - each permutation P.
//   - how much operation 2 applied on it.
// What we need to know is when to make operation 2.
// each permutation P[i] will need to K[i] + x * X[i] operation of type 2. 
// We know that after the last operation we will add x
// 1
// 1 2 => 2 1
// 1 2 3 => 2 3 1 => 3 1 2
// 1 2 1
