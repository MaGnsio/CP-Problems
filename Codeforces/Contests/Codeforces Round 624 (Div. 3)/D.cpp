/**
 *    author:  MaGnsi0
 *    created: 08.10.2024 19:59:01
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 4, OO = 2e5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int A; cin >> A;
        int B; cin >> B;
        int C; cin >> C;
        tuple<int, int, int, int> res = {OO, OO, OO, OO};
        vector<pair<int, int>> ans_a(N, {OO, OO});
        for (int b = 1; b < N; ++b) {
            for (int a = 1; a * a <= b; ++a) {
                if (b % a) { continue; }
                ans_a[b] = min(ans_a[b], make_pair(abs(A - a), a));
                int a_ = b / a;
                ans_a[b] = min(ans_a[b], make_pair(abs(A - a_), a_));
            }
        }
        for (int c = 1; c < N; ++c) {
            for (int b = 1; b * b <= c; ++b) {
                if (c % b) { continue; }
                {
                    int a = ans_a[b].second;
                    int ops = ans_a[b].first + abs(B - b) + abs(C - c);
                    res = min(res, make_tuple(ops, a, b, c));
                }
                {
                    int b_ = c / b;
                    int a = ans_a[b_].second;
                    int ops = ans_a[b_].first + abs(B - b_) + abs(C - c);
                    res = min(res, make_tuple(ops, a, b_, c));
                }
            }
        }
        cout << get<0>(res) << "\n";
        cout << get<1>(res) << " " << get<2>(res) << " " << get<3>(res) << "\n";
    }
}
