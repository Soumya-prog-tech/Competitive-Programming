//  D. Goods on the Shelf

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> vals(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        vals[i] = a[i];
    }

    // Coordinate compression for fast O(1) array lookups
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int M = vals.size();

    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
    }

    vector<int> first_pos(M, -1), last_pos(M, -1);
    for (int i = 0; i < n; i++) {
        if (first_pos[a[i]] == -1) first_pos[a[i]] = i;
        last_pos[a[i]] = i;
    }

    // Find the first broken block from the left
    int L = -1;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1] && last_pos[a[i - 1]] > i - 1) {
            L = i;
            break;
        }
    }

    if (L == -1) {
        cout << "YES\n";
        return;
    }

    // Find the first broken block from the right
    int R = -1;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] != a[i + 1] && first_pos[a[i + 1]] < i + 1) {
            R = i;
            break;
        }
    }

    vector<int> C;
    auto add_cand = [&](int idx) {
        if (idx >= 0 && idx < n) C.push_back(idx);
    };

    // Gather left candidates
    add_cand(L - 1);
    if (L - 1 >= 0) {
        add_cand(first_pos[a[L - 1]]);
        add_cand(last_pos[a[L - 1]]);
    }
    add_cand(L);
    if (L < n) {
        add_cand(first_pos[a[L]]);
        add_cand(last_pos[a[L]]);
    }

    // Gather right candidates
    if (R != -1) {
        add_cand(R + 1);
        if (R + 1 < n) {
            add_cand(first_pos[a[R + 1]]);
            add_cand(last_pos[a[R + 1]]);
        }
        add_cand(R);
        if (R >= 0) {
            add_cand(first_pos[a[R]]);
            add_cand(last_pos[a[R]]);
        }
    }

    // Isolate unique candidates
    sort(C.begin(), C.end());
    C.erase(unique(C.begin(), C.end()), C.end());

    vector<int> seen(M, 0);
    int query_id = 0;

    // Highly branch-predicted O(N) check
    auto isValid = [&]() {
        query_id++;
        seen[a[0]] = query_id;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1]) {
                if (seen[a[i]] == query_id) return false;
                seen[a[i]] = query_id;
            }
        }
        return true;
    };

    bool possible = false;
    for (size_t i = 0; i < C.size(); i++) {
        for (size_t j = i; j < C.size(); j++) {
            swap(a[C[i]], a[C[j]]);
            if (isValid()) {
                possible = true;
                break;
            }
            // Backtrack
            swap(a[C[i]], a[C[j]]);
        }
        if (possible) break;
    }

    if (possible) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
