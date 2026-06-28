#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& visited, vector<vector<int>>& adj, bool& allDeg2) {
    visited[node] = 1;
    if (adj[node].size() != 2) allDeg2 = false;   // degree check
    for (auto& nei : adj[node]) {
        if (!visited[nei]) {
            dfs(nei, visited, adj, allDeg2);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> visited(n+1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bool allDeg2 = true;
            dfs(i, visited, adj, allDeg2);
            if (allDeg2) ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}