/**
 *    author:  MaGnsi0
 *    created: 05.02.2023 09:14:10
**/
#include <bits/stdc++.h>

using namespace std;

struct node {
    int C[2], height;
    bool colored;
    string id;
    node() {
        C[0] = C[1] = -1;
        height = 0;
        id = "";
    }
    node(string x, int h) {
        C[0] = C[1] = -1;
        colored = false;
        height = h;
        id = x;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<string> leafs;
    for (int i = 1; i <= q; ++i) {
        string leaf;
        cin >> leaf;
        leafs.push_back(leaf);
        string ans = ".";
        for (int j = n; j >= 1; --j) {
            bool ok = true;
            for (int k = 0; k < i; ++k) {
                if (leafs[k].substr(0, j) != leafs[0].substr(0, j)) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = leafs[0].substr(0, j);
                break;
            }
        }
        cout << ans << "\n";
    }
}
