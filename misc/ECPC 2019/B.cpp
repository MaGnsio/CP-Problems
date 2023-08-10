/**
 *    author:  MaGnsi0
 *    created: 17.07.2023 12:37:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("gcd.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        vector<vector<vector<int64_t>>> a(X, vector<vector<int64_t>>(Y, vector<int64_t>(Z)));
        for (int z = 0; z < Z; ++z) {
            for (int x = 0; x < X; ++x) {
                for (int y = 0; y < Y; ++y) {
                    cin >> a[x][y][z];
                }
            }
        }
        int64_t g_outer = 0;
        for (int z = 0; z < Z; ++z) {
            for (int x = 0; x < X; ++x) {
                for (int y = 0; y < Y; ++y) {
                    if (x == 0 || y == 0 || z == 0) {
                        g_outer = __gcd(g_outer, a[x][y][z]);
                    }
                }
            }
        }
        vector<int64_t> factors;
        for (int64_t i = 2; i * i <= g_outer; ++i) {
            if (g_outer % i == 0) { factors.push_back(i); }
            while (g_outer % i == 0) { g_outer /= i; }
        }
        if (g_outer > 1) { factors.push_back(g_outer); }
        sort(factors.rbegin(), factors.rend());
        function<bool(int64_t)> F = [&](int64_t p) {
            int minX = X, maxX = 0;
            int minY = Y, maxY = 0;
            int minZ = Z, maxZ = 0;
            for (int z = 0; z < Z; ++z) {
                for (int x = 0; x < X; ++x) {
                    for (int y = 0; y < Y; ++y) {
                        if (a[x][y][z] % p) {
                            minX = min(minX, x);
                            maxX = max(maxX, x);
                            minY = min(minY, y);
                            maxY = max(maxY, y);
                            minZ = min(minZ, z);
                            maxZ = max(maxZ, z);
                        }
                    }
                }
            }
            int64_t g = 0;
            for (int z = 0; z < Z; ++z) {
                for (int x = 0; x < X; ++x) {
                    for (int y = 0; y < Y; ++y) {
                        if (minX <= x && x <= maxX && minY <= y && y <= maxY && minZ <= z && z <= maxZ) {
                            continue;
                        }
                        g = __gcd(g, a[x][y][z]);
                    }
                }
            }
            return (g == p);
        };
        int64_t ans = 1;
        for (int64_t p : factors) {
            if (F(p)) {
                ans = p;
                break;
            }
        }
        cout << ans << "\n";
    }
}
