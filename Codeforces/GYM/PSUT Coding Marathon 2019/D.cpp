/**
 *    author:  MaGnsi0
 *    created: 21/09/2021 21:15:41
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<pair<int, int>> p(n / 2);
    for (int i = 0; i < n / 2; ++i) {
        cin >> p[i].first >> p[i].second;
        if (p[i].first < p[i].second) {
            swap(p[i].first, p[i].second);
        }
    }
    sort(p.begin(), p.end(), greater<pair<int, int>>());
    vector<int> L, R;
    L.push_back(p[0].first);
    R.push_back(p[0].second);
    for (int i = 1; i < n / 2; ++i) {
        if (L.back() <= R.back()) {
            if (p[i].first <= L.back()) {
                L.push_back(p[i].first);
                L.push_back(p[i].second);
                continue;
            } else if (p[i].first <= R.back()) {
                R.push_back(p[i].first);
                R.push_back(p[i].second);
                continue;
            }
        } else {
            if (p[i].first <= R.back()) {
                R.push_back(p[i].first);
                R.push_back(p[i].second);
                continue;
            } else if (p[i].first <= L.back()) {
                L.push_back(p[i].first);
                L.push_back(p[i].second);
                continue;
            }
        }
        cout << -1;
        return 0;
    }
    if (L.size() == 1) {
        reverse(R.begin(), R.end());
        for (int i = 0; i < (int)R.size() - 1; ++i) {
            cout << R[i] << " ";
        }
        cout << L[0] << " " << R[(int)R.size() - 1] << "\n";
    } else {
        reverse(L.begin(), L.end());
        for (int i = 0; i < (int)L.size(); ++i) {
            cout << L[i] << " ";
        }
        for (int i = 0; i < (int)R.size(); ++i) {
            cout << R[i] << " ";
        }
    }
}
