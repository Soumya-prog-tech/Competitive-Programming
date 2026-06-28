//  B. Most socially-distanced subsequence

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int i = 0;
    vector<int> v;
    v.push_back(a[i]);
    while (i<n) {
        int j = i+1;
        if (j<n && a[j] > a[i]) {
            while (j<n && a[j] > a[j-1]) j++;
        }
        else if (j<n && a[j] < a[i]){
            while (j<n && a[j] < a[j-1]) j++;
        }
        if (j==n) {
            v.push_back(a[n-1]);
            break;
        }
        else {
            v.push_back(a[j-1]);
            i = j-1;
        }
    }
    cout<<v.size()<<endl;
    for (const auto& x : v) cout<<x<<" ";
    cout<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
