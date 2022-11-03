/**
 *    author:  MaGnsi0
 *    created: 13.06.2022 09:35:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    function<char(int)> ask_1 = [](int i) {
        char c;
        cout << "? 1 " << i + 1 << endl;
        cin >> c;
        return c;
    };
    function<int(int, int)> ask_2 = [](int l, int r) {
        int x;
        cout << "? 2 " << l + 1 << " " << r + 1 << endl;
        cin >> x;
        return x;
    };
    vector<int> pos;
    vector<char> s(n, ' ');
    s[0] = ask_1(0);
    pos.push_back(0);
    for (int i = 1, old_cnt = 1; i < n; ++i) {
        if (ask_2(0, i) == old_cnt + 1) {
            s[i] = ask_1(i);
            pos.push_back(i);
            old_cnt++;
        } else {
            int m = (int)pos.size();
            sort(pos.begin(), pos.end());
            int l = 0, r = m - 1, best = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (ask_2(pos[mid] + 1, i) == m - mid) {
                    best = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            assert(best != -1);
            s[i] = s[pos[best]];
            pos[best] = i;
        }
    }
    cout << "! ";
    for (int i = 0; i < n; ++i) {
        cout << s[i];
    }
    cout << endl;
}
