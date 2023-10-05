/**
 *    author:  MaGnsi0
 *    created: 28/09/2021 16:19:17
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        deque<int> q;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (q.empty() || x < q.front()) {
                q.push_front(x);
            } else {
                q.push_back(x);
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << q[i] << " ";
        }
        cout << "\n";
    }
}
