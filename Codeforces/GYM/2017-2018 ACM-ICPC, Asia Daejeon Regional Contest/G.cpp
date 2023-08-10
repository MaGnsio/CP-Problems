#include <bits/stdc++.h>

using namespace std;

const int N = 51000;
int a[N], b[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
         int n, m;
         cin>>n>>m;

         {
                  int x = -10;
                  int y; cin>>y;

                  for(int i = 0; i < n; i++)
                  {
                           int x1, y1;
                           cin>>x1>>y1;
                           while(x < x1)
                           {
                                    a[x + 10]= y;
                                    ++x;
                           }
                           y = y1;
                  }
                  while(x + 10 < N)
                  {
                           a[x + 10] = y;
                           ++x;
                  }
         }
         {
                  int x = -10;
                  int y; cin>>y;
                  
                  for(int i = 0; i < m; i++)
                  {
                           int x1, y1;
                           cin>>x1>>y1;
                           while(x < x1)
                           {
                                    b[x + 10]= y;
                                    ++x;
                           }
                           y = y1;
                  }
                  while(x + 10 < N)
                  {
                           b[x + 10] = y;
                           ++x;
                  }
         }
         int64_t ans1 = 0, ans2 = 0, L = N - 1, R = 0;
         for (int64_t i = 1; i < N; ++i) {
             if (b[i] > a[i] && b[i - 1] < a[i - 1]) {
                 L = min(L, i);
                 R = max(R, i);
             }
             if (b[i] < a[i] && b[i - 1] > a[i - 1]) {
                 L = min(L, i);
                 R = max(R, i);
             }
         }
         for (int i = L; i < R; ++i) {
             ans1 += max(0, b[i] - a[i]);
         }
         for (int i = 1; i < R; ++i) {
             int r = max(0, b[i] - a[i]);
             int c = max(0, b[i - 1] - a[i - 1]);
             //ans2 += (b[i] > a[i]) && (b[i - 1] < a[i - 1]);
             ans2 += r && !c;
         }
         cout << ans2 << " " << ans1;
}
