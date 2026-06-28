//  Message Route

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for (int i = 0; i<m; i++) {
        int a, b;
        cin>>a>>b;
        edges.push_back({a, b});
    }
    vector<vector<int>> adj(n+1);
    for (int i = 0; i<m; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    queue<int> q;
    vector<int> visited(n+1, 0);
    vector<int> parent(n+1, -1);
    q.push(1);
    visited[1] = 1;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i<sz; i++) {
            int curr = q.front();
            q.pop();
            if (curr == n) {
                vector<int> v{n};
                while (v.back() != 1) {
                    v.push_back(parent[v.back()]);
                }
                reverse(v.begin(), v.end());
                cout<<v.size()<<endl;
                for (int i = 0; i<v.size(); i++) {
                    cout<<v[i]<<" ";
                }
                cout<<endl;
                return;
            }
            for (int j = 0; j<adj[curr].size(); j++) {
                if (!visited[adj[curr][j]]) {
                    parent[adj[curr][j]] = curr;
                    visited[adj[curr][j]] = 1;
                    q.push(adj[curr][j]);
                }
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}

int main() {
    int t = 1;
    // cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
