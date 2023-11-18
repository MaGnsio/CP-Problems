#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define int long long

const int N = 1009;
int x[N], y[N], n;

int solve_point(){
         map<pair<int,int>, int> mp;
         for(int i = 0; i < n; i++){
                  for(int j = i + 1; j < n; j++){
                           mp[{x[i] + x[j], y[i] + y[j]}] += 2;
                  }
         }
         int mx= 0;
         for(auto [k, v] : mp){
                  auto [X, Y]= k;
                  for(int i = 0; i < n; i++){
                           if(2 * x[i] == X && 2 * y[i] == Y)
                                    v++;
                  }
                  mx= max(mx, v);
         }
         return n - mx;
}

array<int, 3> normalize(int num, int den){
         int g = __gcd(abs(num), abs(den));
         num /= g;
         den /= g;

         int sgn = 1;
         if(num < 0) sgn *= -1;
         if(den < 0) sgn *= -1;
         if (num == 0) sgn = 1;

         return {sgn, abs(num), abs(den)};
}
int solve_line(){
         //Y = m * x + b
         map<int,int> vertical_lines, horizontal_lines;
         map<pair<array<int, 3>, array<int, 3>>, int> lines;
         for(int i = 0; i < n; i++){
                  for(int j = i + 1; j < n; j++){
                           int dy = y[j] - y[i];
                           int dx = x[j] - x[i];

                           if(dx == 0){
                                    vertical_lines[x[i] * 2];
                           }else if(dy == 0){
                                    horizontal_lines[y[i] * 2];
                           }else{
                                    auto m = normalize(dy, dx);
                                    auto b = normalize(dx * y[i] - dy * x[i],
                                                       dx);
                                    lines[{m, b}];
                           }
                           if(dy == 0)
                           {
                                    vertical_lines[x[i] + x[j]] += 2;
                           }
                           else if(dx == 0)
                           {
                                    horizontal_lines[y[i] + y[j]] += 2;
                                    continue;
                           }else{
                                    auto m = normalize(-dx, dy);
                                    auto b = normalize(y[j]*y[j] - y[i]*y[i] +  x[j]*x[j] - x[i]*x[i],
                                                       (y[j] - y[i]) * 2);

                                    lines[{m, b}] += 2;
                           }
                  }
         }

         for(int i = 0; i < n; i++){
                  vertical_lines[2 * x[i]]++;
                  horizontal_lines[2 * y[i]]++;
         }

         for(auto &[k, v] : lines){
                  for(int i = 0; i < n; i++) {
                           auto [m, b] = k;
                           if ((x[i] * m[0] * m[1] * b[2]) + (b[0] * b[1] * m[2]) == y[i] * b[2] * m[2])
                                    v++;
                  }
         }

         int mx= 0;
         for(auto [k, v] : vertical_lines)
                  mx= max(mx, v);
         for(auto [k, v] : horizontal_lines)
                  mx= max(mx, v);
         for(auto [k, v] : lines)
                  mx= max(mx, v);

         return n - mx;
}
int32_t main() {
         cin.tie(0);
         cin.sync_with_stdio(0);

         cin>>n;
         for(int i = 0; i < n; i++)
                  cin>>x[i]>>y[i];

         int res= min(solve_point(), solve_line());
         res= min(res, n - 1);
         cout<<res<<"\n";
}
