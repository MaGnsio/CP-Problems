/**
 *    author:  MaGnsi0
 *    created: 19.10.2024 22:19:02
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class FenwickTree2D {
 public:
  vector<vector<T>> fenw;
  int n, m;

  FenwickTree2D() : n(0), m(0) {}
  FenwickTree2D(int n_, int m_) : n(n_), m(m_) {
    fenw.resize(n);
    for (int i = 0; i < n; i++) {
      fenw[i].resize(m);
    }
  }

  void Modify(int i, int j, T v) {
    assert(0 <= i && i < n && 0 <= j && j < m);
    int x = i;
    while (x < n) {
      int y = j;
      while (y < m) {
        fenw[x][y] += v;
        y |= y + 1;
      }
      x |= x + 1;
    }
  }

  T Query(int i, int j) {
    assert(0 <= i && i <= n && 0 <= j && j <= m);
    T v{};
    int x = i;
    while (x > 0) {
      int y = j;
      while (y > 0) {
        v += fenw[x - 1][y - 1];
        y &= y - 1;
      }
      x &= x - 1;
    }
    return v;
  }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        int n; cin >> n;
        int m; cin >> m;
        int64_t k; cin >> k;
        vector a(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j]; a[i][j]--;
            }
        }
        vector b(n * m, vector<pair<int, int>>());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                b[a[i][j]].emplace_back(i, j);
            }
        }
        FenwickTree2D<int> ft(n, m);
        for (auto bv : b) {
            for (auto [i, j] : bv) {
                ft.Modify(i, j, +1);
            }
        }
        function<int64_t(int)> F = [&](int x) {
            int64_t res = 0;
            for (auto bv : b) {
                for (auto [i, j] : bv) {
                    ft.Modify(i, j, -1);
                }
                for (auto [i, j] : bv) {
                    int xl = max(0, i - x);
                    int xr = min(n - 1, i + x);
                    int yl = max(0, j - x);
                    int yr = min(m - 1, j + x);
                    res += ft.Query(xr + 1, yr + 1);
                    res -= (xl ? ft.Query(xl, yr + 1) : 0);
                    res -= (yl ? ft.Query(xr + 1, yl) : 0);
                    res += (xl && yl ? ft.Query(xl, yl) : 0);
                }
                for (auto [i, j] : bv) {
                    ft.Modify(i, j, +1);
                }
            }
            return res;
        };
        int low = 1, high = max(n, m) - 1, ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (F(mid) >= k) {
                ans = mid; high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << endl;
    }
}
