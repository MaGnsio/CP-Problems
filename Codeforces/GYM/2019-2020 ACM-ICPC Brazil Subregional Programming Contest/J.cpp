/**
 *    author:  MaGnsi0
 *    created: 31.10.2023 22:09:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int k; cin >> k;
    map<char, int> val;
    val['A'] = 1, val['2'] = 2;
    val['3'] = 3, val['4'] = 4;
    val['5'] = 5, val['6'] = 6;
    val['7'] = 7, val['8'] = 8;
    val['9'] = 9, val['D'] = 10;
    val['Q'] = 11, val['J'] = 12;
    val['K'] = 13;
    vector<vector<int>> cards(n);
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (char c : s) {
            cards[i].push_back(val[c]);
        }
    }
    int turn = k - 1, joker = k - 1, can_give = 0;
    function<bool(int)> winning = [&](int j) {
        if (joker == j) { return false; }
        sort(cards[j].begin(), cards[j].end());
        return (cards[j].size() == 4) && (cards[j][0] == cards[j][3]);
    };
    for (int i = 0; i < n; ++i) {
        if (winning(i)) {
            cout << i + 1;
            return 0;
        }
    }
    while (true) {
        int next = (turn + 1) % n;
        if (joker == turn && can_give) {
            joker = next;
            can_give = 0;
            if (winning(turn)) {
                cout << turn + 1;
                return 0;
            }
            turn = next;
            continue;
        }
        if (joker == turn) { can_give = 1; }
        vector<int> F(14, 0);
        for (int card : cards[turn]) {
            F[card]++;
        }
        int give = cards[turn][0];
        for (int card : cards[turn]) {
            if ((F[card] < F[give]) || (F[card] == F[give] && card < give)) {
                give = card;
            }
        }
        F[give]--;
        vector<int> new_cards;
        for (int i = 0; i < 14; ++i) {
            while (F[i]--) {
                new_cards.push_back(i);
            }
        }
        cards[turn] = new_cards;
        cards[next].push_back(give);
        if (winning(turn) && winning(next)) {
            cout << min(turn, next) + 1;
            return 0;
        } else if (winning(turn)) {
            cout << turn + 1;
            return 0;
        } else if (winning(next)) {
            cout << next + 1;
            return 0;
        }
        turn = next;
    }
}
