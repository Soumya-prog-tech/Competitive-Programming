//  A. Secret Passwords

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

class DSU {
    vector<int> parent;
    vector<int> rank;
    int n;
    public:
    DSU(int n) {
        this->n = n;
        parent.resize(n);
        rank.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        n--;
        if (rank[x] > rank[y]) {
            parent[y] = x;
            rank[x] += rank[y];
        }
        else {
            parent[x] = y;
            rank[y] += rank[x];
        }
    }
    int noOfComponents() {
        return n;
    }
};

void solve() {
    int n;
    cin>>n;
    vector<string> passwords(n);
    for (int i = 0; i<n; i++) {
        cin>>passwords[i];
    }
    unordered_map<char, vector<int>> nodes;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<passwords[i].size(); j++) {
            nodes[passwords[i][j]].push_back(i);
        }
    }
    DSU dsu(n);
    for (auto& [key, val]: nodes) {
        if (val.size() > 1) {
            for (int i = 0; i<val.size()-1; i++) {
                dsu.unite(val[i], val[i+1]);
            }
        }
    }
    cout<<dsu.noOfComponents()<<endl;
}

int main() {
    int t = 1;
    // cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
