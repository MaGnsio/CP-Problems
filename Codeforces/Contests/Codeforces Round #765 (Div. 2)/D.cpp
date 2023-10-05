/**
 *    author:  MaGnsi0
 *    created: 02.02.2022 00:49:41
**/
#include <bits/stdc++.h>

using namespace std;

struct trie {
    struct node {
        int x = 0, y = -1;
        node* c[2] = {nullptr};
    };
    node* root;
    trie () {
        root = new node();
    }
    void insert(int n, int res, int idx) {
        node* cur_node = root;
        for (int b = 30; b >= 0; --b) {
            int b_n = (n >> b) & 1;
            if (cur_node -> c[b_n] == nullptr) {
                cur_node -> c[b_n] = new node();
            }
            cur_node = cur_node -> c[b_n];
            if (cur_node -> x < res) {
                cur_node -> x = res;
                cur_node -> y = idx;
            }
        }
    }
    pair<int, int> solve(int n, int k) {
        pair<int, int> res = {0, -1};
        node* cur_node = root;
        for (int b = 30; b >= 0; --b) {
            int b_n = (n >> b) & 1;
            int b_k = (k >> b) & 1;
            if (!b_k) {
                if (cur_node -> c[!b_n] != nullptr) {
                    if (cur_node -> c[!b_n] -> x > res.first) {
                        res.first = cur_node -> c[!b_n] -> x;
                        res.second = cur_node -> c[!b_n] -> y;
                    }
                }
                if (cur_node -> c[b_n] != nullptr) {
                    cur_node = cur_node -> c[b_n];
                } else {
                    return res;
                }
            } else {
                if (cur_node -> c[!b_n] != nullptr) {
                    cur_node = cur_node -> c[!b_n];
                } else {
                    return res;
                }
            }
        }
        if (cur_node -> x > res.first) {
            res.first = cur_node -> x;
            res.second = cur_node -> y;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    if (k == 0) {
        cout << n << "\n";
        for (int i = 1; i <= n; ++i) {
            cout << i << " ";
        }
        return 0;
    }
    sort(a.begin(), a.end());
    trie t;
    vector<int> dp(n, 0), p(n, -1);
    for (int i = 0; i < n; ++i) {
        pair<int, int> ans = t.solve(a[i].first, k);
        dp[i] = ans.first + 1;
        p[i] = ans.second;
        t.insert(a[i].first, dp[i], i);
    }
    int res = *max_element(dp.begin(), dp.end()); 
    if (res == 1) {
        cout << -1;
        return 0;
    }
    cout << res << "\n";
    for (int i = n - 1; i >= 0; --i) {
        if (dp[i] == res) {
            int j = i;
            cout << a[j].second;
            while (p[j] != -1) {
                cout << " " << a[p[j]].second;
                j = p[j];
            }
            break;
        }
    }
}
