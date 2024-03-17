/**
 *    author:  MaGnsi0
 *    created: 25.01.2024 20:12:59
**/
#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 18), M = 18;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> club(n, 0);
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (char c : s) {
            club[i] |= (1 << (c - 'a'));
        }
    }
    string S; cin >> S;
    vector<int> F(N), A(N);
    for (int i = 0; i < n; ++i) {
        F[club[i]]++;
    }
    for (int m = 0; m < N; ++m) {
        for (int s = m; ; s = (s - 1) & m) {
            if (F[s]) { A[m]++; }
            if (s == 0)  break;
        }
    }
    vector<set<int>> a(M);
    for (int i = 0; i < (int)S.size(); ++i) {
        a[S[i] - 'a'].insert(i);
    }
    int64_t ans = 0;
    for (int i = 0; i < (int)S.size(); ++i) {
        vector<pair<int, int>> nexts;
        for (int j = 0; j < M; ++j) {
            auto it = a[j].lower_bound(i);
            if (it == a[j].end()) { continue; }
            nexts.emplace_back(*it, j);
        }
        sort(nexts.begin(), nexts.end());
        int m = 0;
        for (auto [j, c] : nexts) {
            m |= (1 << c);
            if (A[m] != 0) {
                ans += (int)S.size() - j;
                break;
            }
        }
    }
    cout << ans;
}
