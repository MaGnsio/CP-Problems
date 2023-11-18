/**
 *    author:  MaGnsi0
 *    created: 27.09.2023 18:04:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t N, M, C;
    cin >> N >> M >> C;
    int64_t ans = INT64_MAX, m_ans = -1, c_ans = -1;
    for (int m = 0; m <= 4000000; ++m) {
        int64_t R = N - m * M;
        if (R <= 0) {
            if (abs(R) < ans) {
                ans = abs(R);
                m_ans = m;
                c_ans = 0;
            }
        } else {
            {
                int64_t c = R / C;
                int64_t val = abs(m * M + c * C - N);
                if (val < ans) {
                    ans = val;
                    m_ans = m;
                    c_ans = c;
                }
            }
            {
                int64_t c = (R + C - 1) / C;
                int64_t val = abs(m * M + c * C - N);
                if (val < ans) {
                    ans = val;
                    m_ans = m;
                    c_ans = c;
                }
            }
        }
    }
    cout << m_ans << " " << c_ans;
}
