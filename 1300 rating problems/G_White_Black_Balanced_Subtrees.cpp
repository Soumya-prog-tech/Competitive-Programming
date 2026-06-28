//  G. White-Black Balanced Subtrees

#include<bits/stdc++.h>

using namespace std;

// #define DEBUG
#define ll long long

int ans;

pair<int, int> dfs(int u, string& s, vector<vector<int>>& adjList, vector<int>& visited) {
    visited[u] = 1;
    pair<int, int> res = {0, 0};
    for (auto& nei : adjList[u]) {

        if (visited[nei]) continue;
        pair<int, int> p = dfs(nei, s, adjList, visited);
        res.first += p.first;
        res.second += p.second;
    }
    if (s[u] == 'B') {
        res.first++;
    }
    else {
        res.second++;
    }
#ifdef DEBUG
    cout<<u<<" "<<res.first<<" "<<res.second<<endl;
#endif
    if (res.first == res.second) ans++;
    // cout<<ans<<endl;
    return res;
}

void solve() {
    int n;
    cin>>n;
#ifdef DEBUG
    cout<<n<<endl;
#endif
    vector<int> a(n-1);
    for (int i = 0; i<n-1; i++) {
        cin>>a[i];
        a[i] -=1;
    }
#ifdef DEBUG
    for (auto& x : a) cout<<x<<" ";
    cout<<endl;
#endif
    string s;
    cin>>s;
#ifdef DEBUG
    cout<<s<<endl;
#endif
    vector<vector<int>> adjList(n);
    for (int i = 0; i<n-1; i++) {
        adjList[a[i]].push_back(i+1);
        adjList[i+1].push_back(a[i]);
    }
    ans = 0;
    vector<int> visited(n, 0);
    dfs(0, s, adjList, visited);
    cout<<ans<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
