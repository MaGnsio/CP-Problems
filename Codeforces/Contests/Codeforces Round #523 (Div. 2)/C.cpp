/**
 *    author:  MaGnsi0
 *    created: 13/09/2021 23:45:57
**/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6, MOD = 1e9 + 7;

int main() {
   ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
   int n;
   cin >> n;
   vector<int> v(n);
   for (int i = 0; i < n; ++i) {
      cin >> v[i];
   }
   vector<int> dp(N, 0);
   dp[0] = 1;
   for (int i = 0; i < n; ++i) {
      vector<int> divisors;
      for (int j = 1; j * j <= v[i]; ++j) {
         if (v[i] % j == 0) {
            divisors.push_back(j);
            if (v[i] != j * j) {
               divisors.push_back(v[i] / j);
            }
         }
      }
      sort(divisors.begin(), divisors.end(), greater<int>());
      for (auto& divisor : divisors) {
         dp[divisor] += dp[divisor - 1];
         dp[divisor] %= MOD;
      }
   }
   for (int i = 2; i <= n; ++i) {
      dp[i] += dp[i - 1];
      dp[i] %= MOD;
   }
   cout << dp[n];
}
