/**
 *    author:  MaGnsi0
 *    created: 07.08.2024 20:21:21
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, B = 500;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _; cin >> _;
    int Q; cin >> Q;
    vector<int> ans_block(B, -1);
    vector<int> ans_point(N, -1);
    function<void(int, int, int)> update_points = [&](int low, int high, int val) {
        for (int i = low; i <= high; ++i) {
            ans_point[i] = max(ans_point[i], val);
        }
    };
    function<void(int, int, int)> update_blocks = [&](int low, int high, int val) {
        for (int i = low; i <= high; ++i) {
            ans_block[i] = max(ans_block[i], val);
        }
    };
    function<int(int, int)> get = [&](int low, int high) {
        int ans = 0, j = low;
        while (j <= high) {
            int nxt = max(ans_point[j], ans_block[j / B]);
            if (nxt == -1) { return -1; }
            j = nxt + 1; ans++;
        }
        return ans;
    };
    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int l; cin >> l;
            int r; cin >> r;
            int bl = l / B;
            int br = r / B;
            if (bl == br) {
                update_points(l, r, r);
            } else {
                update_points(l, bl * B + B - 1, r);
                update_blocks(bl + 1, br - 1, r);
                update_points(br * B, r, r);
            }
        } else {
            int l; cin >> l;
            int r; cin >> r;
            cout << get(l, r) << "\n";
        }
    }
}
