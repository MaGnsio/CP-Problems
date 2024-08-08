/**
 *    author:  MaGnsi0
 *    created: 08.08.2024 20:21:00
**/
#include <bits/stdc++.h>

using namespace std;

const int B = 20;
 
struct xor_basis {
    array<int, B> I, basis;
    xor_basis() { basis.fill(0); }
    xor_basis(int x, int i) {
        I.fill(-1);
        basis.fill(0);
        for (int b = B - 1; b >= 0; --b) {
            if (x >> b & 1) {
                basis[b] = x;
                I[b] = i;
                break;
            }
        }
    }
    void insert(int x, int i) {
        for (int b = B - 1; b >= 0; --b) {
            if (!(x >> b & 1)) { continue; }
            if (!basis[b]) {
                I[b] = i; basis[b] = x;
                return;
            } else {
                if (i > I[b]) {
                    swap(I[b], i);
                    swap(basis[b], x);
                }
                x ^= basis[b];
            }
        }
    }
    int max(int l) {
        int res = 0;
        for (int b = B - 1; b >= 0; --b) {
            if (I[b] < l) { continue; }
            if (!basis[b]) { continue; }
            if (res >> b & 1) { continue; }
            res ^= basis[b];
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<xor_basis> b(n); b[0] = xor_basis(a[0], 0);
    for (int i = 1; i < n; ++i) {
        b[i] = b[i - 1];
        b[i].insert(a[i], i);
    }
    int Q; cin >> Q;
    while (Q--) {
        int l; cin >> l; l--;
        int r; cin >> r; r--;
        cout << b[r].max(l) << "\n";
    }
}
