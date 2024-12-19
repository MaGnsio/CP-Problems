/**
 *    author:  MaGnsi0
 *    created: 22.09.2024 17:57:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int nimber = 0;
        map<int, set<int>> mp;
        for (int i = 0; i < n; ++i) {
            nimber ^= a[i];
        }
        function<int(int)> msb = [&](int x) {
            for (int b = 31; b >= 0; --b) {
                if (x >> b & 1) {
                    return b;
                }
            }
            return -1;
        };
        function<void(int, int)> remove_bits = [&](int i, int x) {
            for (int b = 31; b >= 0; --b) {
                if (x >> b & 1) {
                    mp[b].erase(i);
                }
            }
        };
        function<void(int, int)> add_bits = [&](int i, int x) {
            for (int b = 31; b >= 0; --b) {
                if (x >> b & 1) {
                    mp[b].insert(i);
                }
            }
        };
        function<bool(int, int)> remove = [&](int j, int x) {
            nimber ^= a[j]; remove_bits(j, a[j]);
            cout << j + 1 << " " << x << endl;
            a[j] -= x; nimber ^= a[j]; add_bits(j, a[j]);
            int i; cin >> i; i--;
            int y; cin >> y;
            if (i == -1) { return false; }
            nimber ^= a[i]; remove_bits(i, a[i]);
            a[i] -= y; nimber ^= a[i]; add_bits(i, a[i]);
            return true;
        };
        function<bool()> play = [&]() {
            int b = msb(nimber);
            assert(!mp[b].empty());
            int j = *mp[b].begin();
            int x = a[j] - (nimber ^ a[j]);
            return remove(j, x);
        };
        for (int i = 0; i < n; ++i) {
            add_bits(i, a[i]);
        }
        if (nimber == 0) {
            cout << "0 0" << endl;
            int i; cin >> i; i--;
            int y; cin >> y;
            nimber ^= a[i]; remove_bits(i, a[i]);
            a[i] -= y; nimber ^= a[i]; add_bits(i, a[i]);
        }
        while (play()) {}
    }
}
