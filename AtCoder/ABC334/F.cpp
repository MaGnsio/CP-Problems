/**
 *    author:  MaGnsi0
 *    created: 24.12.2023 17:30:22
**/
#include <bits/stdc++.h>

using namespace std;

const double OO = 1e17;

template <typename T>
struct segment_tree {
    int N;
    T E;
    vector<T> S;
    function<T(T, T)> F;
    segment_tree(int n, T e, function<T(T, T)> f) : N(n), E(e), S(2 * n, e), F(f) {}
    void update(int j, T x) {
        for (S[j += N] = x; j /= 2;) {
            S[j] = F(S[2 * j], S[2 * j + 1]);
        }
    }
    T query(int L, int R) {
        T l = E, r = E;
        for (L += N, R += N; L < R; L /= 2, R /= 2) {
            if (L % 2) {
                l = F(l, S[L++]);
            }
            if (R % 2) {
                r = F(S[--R], r);
            }
        }
        return F(l, r);
    }
};

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int n; cin >> n;
   int k; cin >> k;
   vector<int64_t> X(n + 1), Y(n + 1);
   for (int i = 0; i <= n; ++i) {
       cin >> X[i] >> Y[i];
   }
   function<double(int, int)> D = [&](int i, int j) {
       double dx = X[i] - X[j];
       double dy = Y[i] - Y[j];
       return sqrt(dx * dx + dy * dy);
   };
   vector<double> dp(n + 1);
   segment_tree<double> A(n + 1, OO, [](double x, double y) { return min(x, y); });
   dp[n] = 2 * D(0, n);
   A.update(n, D(n - 1, 0) + dp[n] - D(n - 1, n));
   for (int i = n - 1; i; --i) {
       int low = i + 1;
       int high = min(n, i + k);
       dp[i] = D(0, i) + A.query(low, high + 1);
       if (i + k > n) {
           dp[i] = min(dp[i], D(0, i) + D(n, 0));
       }
       A.update(i, D(i - 1, 0) + dp[i] - D(i - 1, i));
   }
   double ans = dp[1];
   for (int i = 2; i <= n; ++i) {
       ans += D(i, i - 1);
   }
   cout << fixed << setprecision(15) << ans;
}
