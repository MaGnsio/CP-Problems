/**
 *    author:  MaGnsi0
 *    created: 05.03.2022 13:54:55
**/
#include <bits/stdc++.h>

using namespace std;

char F(long long t, long long pos, long long root) {
    if (t == 0) {
        return root;
    }
    if (pos == 0) {
        long long r = (t % 3);
        if (root == 'A') {
            return (r == 0 ? 'A' : (r == 1 ? 'B' : 'C'));
        } else if (root == 'B') {
            return (r == 0 ? 'B' : (r == 1 ? 'C' : 'A'));
        } else {
            return (r == 0 ? 'C' : (r == 1 ? 'A' : 'B'));
        }
    }
    long long mid = 1LL << (t - 1);
    if (pos < mid) {
        return F(t - 1, pos, (root == 'A' ? 'B' : (root == 'B' ? 'C' : 'A')));
    } else {
        return F(t - 1, pos - mid, (root == 'A' ? 'C' : (root == 'B' ? 'A' : 'B')));
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    string s;
    cin >> s >> q;
    while (q--) {
        long long t, k;
        cin >> t >> k;
        long long j = 1;
        for (long long i = 0; i < t && j < (long long)1e18; ++i) {
            j *= 2LL;
        }
        long long pos = k - ((k - 1) / j) * j - 1;
        char root = s[(k - 1) / j];
        if (t > 60) {
            long long r = (t - 60) % 3;
            if (root == 'A') {
                root = (r == 0 ? 'A' : (r == 1 ? 'B' : 'C'));
            } else if (root == 'B') {
                root = (r == 0 ? 'B' : (r == 1 ? 'C' : 'A'));
            } else {
                root = (r == 0 ? 'C' : (r == 1 ? 'A' : 'B'));
            }
            t = 60;
        }
        cout << F(t, pos, root) << "\n";
    }
}
