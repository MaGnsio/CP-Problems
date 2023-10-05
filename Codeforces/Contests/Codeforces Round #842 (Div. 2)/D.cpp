/**
 *    author:  MaGnsi0
 *    created: 06.01.2023 21:56:41
**/
#include <bits/stdc++.h>

using namespace std;

struct union_find {
    vector<int> parent, length;
    union_find(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        length = vector<int>(n, 1);
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool unite(int x, int y) {
        int Px = find(x);
        int Py = find(y);
        if (Px == Py) {
            return false;
        }
        if (length[Px] < length[Py]) {
            swap(Px, Py);
        }
        parent[Py] = Px;
        length[Px] += length[Py];
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i]--;
        }
        int ans = 1;
        union_find dsu(n);
        for (int i = 0; i < n; ++i) {
            ans += dsu.unite(a[i], i);
        }
        for (int i = 1; i < n; ++i) {
            if (dsu.find(i) == dsu.find(i - 1)) {
                ans -= 2;
                break;
            }
        }
        cout << ans << "\n";
    }
}
