//  C. Journey

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

double dfs(unordered_map<int, vector<int>>& mp, int node, int parent) {
    double children = 0;
    double sum_children = 0;
    for (auto& nei : mp[node]) {
        if (nei != parent) {
            sum_children += dfs(mp, nei, node);
            children++;
        }
    }
    if (children == 0) return 0.0;
    return 1.0 + (sum_children/children);
}

void solve() {
    int n;
    cin>>n;
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i<n-1; i++) {
        int x, y;
        cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    vector<int> depths;
    cout<<fixed<<setprecision(15)<<dfs(mp, 1, 0);
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
