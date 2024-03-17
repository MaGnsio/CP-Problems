/**
 *    author:  MaGnsi0
 *    created: 17.02.2024 21:15:02
**/
#include <bits/stdc++.h>

using namespace std;

const int D = 7;

const string days[D] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    int k; cin >> k;
    vector<vector<int>> workdays(n);
    for (int i = 0; i < n; ++i) {
        int days_no; cin >> days_no;
        workdays[i].resize(days_no);
        for (int j = 0; j < days_no; ++j) {
            string day; cin >> day;
            workdays[i][j] = find(days, days + D, day) - days;
        }
    }
    vector<int> holidays(m);
    for (int i = 0; i < m; ++i) {
        cin >> holidays[i];
    }
    vector<vector<int>> tasks(k);
    for (int i = 0; i < k; ++i) {
        int parts_no; cin >> parts_no;
        tasks[i].resize(parts_no);
        for (int j = 0; j < parts_no; ++j) {
            cin >> tasks[i][j]; tasks[i][j]--;
        }
        reverse(tasks[i].begin(), tasks[i].end());
    }
    vector<int> work_on(n, -1);
    vector<set<int>> can_do(D), to_do(n);
    for (int task = 0; task < k; ++task) {
        int e = tasks[task].back();
        if (work_on[e] != -1) {
            to_do[e].insert(task);
            continue;
        }
        for (int d : workdays[e]) {
            can_do[d].insert(task);
        }
        work_on[e] = task;
    }
    int finished = 0;
    vector<int> ans(k);
    for (int day = 1, h = 0; finished < k; ++day) {
        if (h < m && holidays[h] == day) { h++; continue; }
        int j = (day - 1) % 7;
        set<int> done, worked;
        for (int task : can_do[j]) {
            if (done.count(task)) { continue; }
            int e = tasks[task].back();
            assert(worked.count(e) == 0);
            tasks[task].pop_back();
            done.insert(task);
            worked.insert(e);
            ans[task] = day;
            work_on[e] = -1;
        }
        for (int task : done) {
            for (int d = 0; d < D; ++d) {
                can_do[d].erase(task);
            }
            if (tasks[task].empty()) {
                finished++;
                continue;
            }
            int e = tasks[task].back();
            worked.insert(e);
            to_do[e].insert(task);
        }
        for (int e : worked) {
            if (to_do[e].empty()) { continue; }
            int task = *to_do[e].begin();
            if (work_on[e] > task) {
                for (int d : workdays[e]) {
                    can_do[d].erase(work_on[e]);
                }
                to_do[e].insert(work_on[e]);
                work_on[e] = -1;
            }
            if (work_on[e] != -1) { continue; }
            to_do[e].erase(to_do[e].begin());
            for (int d : workdays[e]) {
                can_do[d].insert(task);
            }
            work_on[e] = task;
        }
    }
    for (int i = 0; i < k; ++i) {
        cout << ans[i] << " ";
    }
}
