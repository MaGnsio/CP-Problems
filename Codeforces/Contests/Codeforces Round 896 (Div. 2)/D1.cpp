/**
 *    author:  MaGnsi0
 *    created: 10.09.2023 17:25:47
**/
#include <bits/stdc++.h>

using namespace std;

const int M = 30;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    map<int, pair<int, int>> D;
    for (int i = 0; i < M; ++i) {
        D[(1LL << i)] = {i, -1};
        D[-(1LL << i)] = {-1, i};
        for (int j = 0; j < M; ++j) {
            D[(1LL << i) - (1LL << j)] = {i, j};
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int64_t sum = accumulate(a.begin(), a.end(), int64_t(0));
        if (sum % n) {
            cout << "No\n";
            continue;
        }
        sum /= n;
        bool bad = false;
        for (int i = 0; i < n; ++i) {
            if (D.count(sum - a[i]) == 0) {
                bad = true;
            }
        }
        if (bad) {
            cout << "No\n";
            continue;
        }
        vector<int> in(M + 1), out(M + 1);
        for (int i = 0; i < n; ++i) {
            if (a[i] == sum) {
                continue;
            }
            int u, v;
            tie(u, v) = D[sum - a[i]];
            in[u + 1]++, out[v + 1]++;
        }
        for (int i = 0; i <= M; ++i) {
            bad |= in[i] != out[i];
        }
        cout << (bad ? "No" : "Yes") << "\n";
    }
}
