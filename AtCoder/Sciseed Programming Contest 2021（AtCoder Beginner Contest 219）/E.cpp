/**
 *    author:  MaGnsi0
 *    created: 24/09/2021 21:59:38
**/
#include <bits/stdc++.h>
using namespace std;

vector<bool> visited(16);

void dfs(int v, int mask, bool zero) {
    if (visited[v] || ((mask >> v & 1) == zero)) {
        return;
    }
    visited[v] = true;
    if (v % 4 > 0) {
        dfs(v - 1, mask, zero);
    }
    if (v % 4 < 3) {
        dfs(v + 1, mask, zero);
    }
    if (v / 4 > 0) {
        dfs(v - 4, mask, zero);
    }
    if (v / 4 < 3) {
        dfs(v + 4, mask, zero);
    }
}

bool ok(int mask) {
    visited = vector<bool>(16, false);
    for (int i = 0; i < 16; ++i) {
        if (mask >> i & 1) {
            dfs(i, mask, 0);
            break;
        }
    }
    for (int i = 0; i < 16; ++i) {
        if (mask >> i & 1) {
            if (!visited[i]) {
                return false;
            }
        }
    }
    visited = vector<bool>(16, false);
    for (int i = 0; i < 16; ++i) {
        if (i % 4 == 0 || i % 4 == 3 || i / 4 == 0 || i / 4 == 3) {
            dfs(i, mask, 1);
        }
    }
    for (int i = 0; i < 16; ++i) {
        if ((mask >> i & 1) == 0) {
            if (!visited[i]) {
                return false;
            }
        }
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int k = 0;
    for (int i = 0; i < 16; ++i) {
        int x;
        cin >> x;
        if (x == 1) {
            k |= (1 << i);
        }
    }
    int res = 0;
    for (int mask = 0; mask < (1 << 16); ++mask) {
        res += (((mask & k) == k) && ok(mask));
    }
    cout << res;
}
