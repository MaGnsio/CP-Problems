/**
 *    author:  MaGnsi0
 *    created: 10.11.2024 18:31:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector a(3, vector<int>(n));
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j]; a[i][j]--;
            }
        }
        vector<set<pair<int, int>>> c(3);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                c[i].emplace(a[i][j], j);
            }
        }
        vector<int> pcard(n, -1), trader(n, -1);
        set<int> Q, not_deleted;
        function<void(int)> delete_card = [&](int j) {
            for (int i = 0; i < 3; ++i) {
                c[i].erase({a[i][j], j});
            }
        };
        function<void(int)> delete_cards_untill = [&](int j) {
            while (true) {
                auto it = not_deleted.begin();
                if (it == not_deleted.end()) { break; }
                if (*it > j) { break; }
                delete_card(*it);
                not_deleted.erase(it);
            }
        };
        Q.insert(0);
        for (int i = 0; i < n; ++i) {
            not_deleted.insert(i);
        }
        while (!Q.empty()) {
            int card = *Q.begin(); Q.erase(Q.begin());
            delete_cards_untill(card);
            for (int i = 0; i < 3; ++i) {
                while (true) {
                    if (c[i].empty()) { break; }
                    auto it = c[i].begin();
                    int p = it -> first;
                    if (p > a[i][card]) { break; }
                    int new_card = it -> second;
                    if (pcard[new_card] != -1) { continue; }
                    Q.insert(new_card); delete_card(new_card); not_deleted.erase(new_card);
                    pcard[new_card] = card;
                    trader[new_card] = i;
                }
            }
        }
        if (pcard[n - 1] == -1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            string t = "";
            vector<int> cards;
            for (int c = n - 1; c != 0; c = pcard[c]) {
                t += (trader[c] == 0 ? 'Q' : (trader[c] == 1 ? 'K' : 'J'));
                cards.push_back(c);
            }
            int m = (int)cards.size();
            cout << m << "\n";
            for (int i = 0; i < m; ++i) {
                cout << t[m - i - 1] << " " << cards[m - i - 1] + 1 << "\n";
            }
        }
    }
}
