//  B. Lunar New Year and a Wander

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    unordered_map<int, vector<int>> mp;
    int n, m;
    cin>>n>>m;
    for (int i = 0; i<m; i++) {
        int x, y;
        cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> visited(n+1, 0);
    visited[1] = 1;
    pq.push(1);
    vector<int> ans;
    while (!pq.empty()) {
        int curr = pq.top();
        pq.pop();
        ans.push_back(curr);
        for (auto& x : mp[curr]) {
            if (!visited[x]) {
                visited[x] = 1;
                pq.push(x);
            }
        }
    }
    for (auto& x : ans) cout<<x<<" ";
}

int main() {
    int t = 1;
    // cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
