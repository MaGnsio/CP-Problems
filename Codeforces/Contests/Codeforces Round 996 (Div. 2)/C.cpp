/**
 *    author:  MaGnsi0
 *    created: 12.01.2025 16:48:34
**/
#include <bits/stdc++.h>

using namespace std;

int64_t get_sum(int n, int m, string path, vector<vector<int64_t>> a) {
    int64_t sum = 0;
    set<pair<int, int>> row, col;
    vector<set<int>> missingr(n), missingc(m);
    vector<int64_t> r(n, 0), c(m, 0), sumr(n, 0), sumc(m, 0);
    for (int k = 0, i = 0, j = 0; k < n + m - 2; ++k) {
        r[i]++, c[j]++;
        missingr[i].insert(j);
        missingc[j].insert(i);
        if (path[k] == 'D') {
            i++;
        } else {
            j++;
        }
    }
    r[n - 1]++, c[m - 1]++;
    missingr[n - 1].insert(m - 1);
    missingc[m - 1].insert(n - 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sumr[i] += a[i][j];
            sumc[j] += a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (r[i]) { row.emplace(r[i], i); }
    }
    for (int j = 0; j < m; ++j) {
        if (c[j]) { col.emplace(c[j], j); }
    }
    function<void()> do_row = [&]() {
        int i = row.begin() -> second;
        row.erase(row.begin());
        int j = *missingr[i].begin();
        missingr[i].erase(j); r[i]--;
        col.erase({c[j], j}); c[j]--;
        col.emplace(c[j], j);
        missingc[j].erase(i);
        a[i][j] = sum - sumr[i];
        sumc[j] += a[i][j]; sumr[i] += a[i][j];
    };
    function<void()> do_col = [&]() {
        int j = col.begin() -> second;
        col.erase(col.begin());
        int i = *missingc[j].begin();
        missingc[j].erase(i); c[j]--;
        row.erase({r[i], i}); r[i]--;
        row.emplace(r[i], i);
        missingr[i].erase(j);
        a[i][j] = sum - sumc[j];
        sumc[j] += a[i][j]; sumr[i] += a[i][j];
    };
    while (!row.empty() && !col.empty()) {
        if (!row.empty() && row.begin() -> first == 1) {
            do_row();
        } else {
            do_col();
        }
    }
    int64_t max_sum = INT64_MIN, min_sum = INT64_MAX;
    for (int i = 0; i < n; ++i) {
        int64_t sumr = 0;
        for (int j = 0; j < m; ++j) {
            sumr += a[i][j];
        }
        max_sum = max(max_sum, sumr);
        min_sum = min(min_sum, sumr);
    }
    for (int j = 0; j < m; ++j) {
        int64_t sumc = 0;
        for (int i = 0; i < n; ++i) {
            sumc += a[i][j];
        }
        max_sum = max(max_sum, sumc);
        min_sum = min(min_sum, sumc);
    }
    return max_sum - min_sum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        string path; cin >> path;
        vector a(n, vector<int64_t>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        int64_t sum = get_sum(n, m, path, a);
        set<pair<int, int>> row, col;
        vector<set<int>> missingr(n), missingc(m);
        vector<int64_t> r(n, 0), c(m, 0), sumr(n, 0), sumc(m, 0);
        for (int k = 0, i = 0, j = 0; k < n + m - 2; ++k) {
            r[i]++, c[j]++;
            missingr[i].insert(j);
            missingc[j].insert(i);
            if (path[k] == 'D') {
                i++;
            } else {
                j++;
            }
        }
        r[n - 1]++, c[m - 1]++;
        missingr[n - 1].insert(m - 1);
        missingc[m - 1].insert(n - 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                sumr[i] += a[i][j];
                sumc[j] += a[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (r[i]) { row.emplace(r[i], i); }
        }
        for (int j = 0; j < m; ++j) {
            if (c[j]) { col.emplace(c[j], j); }
        }
        function<void()> do_row = [&]() {
            int i = row.begin() -> second;
            row.erase(row.begin());
            int j = *missingr[i].begin();
            missingr[i].erase(j); r[i]--;
            col.erase({c[j], j}); c[j]--;
            col.emplace(c[j], j);
            missingc[j].erase(i);
            a[i][j] = sum - sumr[i];
            sumc[j] += a[i][j]; sumr[i] += a[i][j];
        };
        function<void()> do_col = [&]() {
            int j = col.begin() -> second;
            col.erase(col.begin());
            int i = *missingc[j].begin();
            missingc[j].erase(i); c[j]--;
            row.erase({r[i], i}); r[i]--;
            row.emplace(r[i], i);
            missingr[i].erase(j);
            a[i][j] = sum - sumc[j];
            sumc[j] += a[i][j]; sumr[i] += a[i][j];
        };
        while (!row.empty() && !col.empty()) {
            if (!row.empty() && row.begin() -> first == 1) {
                do_row();
            } else {
                do_col();
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
