//  E1. Rudolf and Snowflakes (simple version)

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

int MAX = 1000001;
vector<bool> dp(MAX, false);

void precompute() {
    for (ll i = 2; 1 + i + i*i <= MAX; i++) {
        ll start = 1 + i + i*i;
        int j = 3;
        while (start<MAX) {
            dp[start] = true;
            start += pow(i, j);
            j++;
        }
    }
}

void solve() {
    int n;
    cin>>n;
    if (dp[n]) {
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}

int main() {
    precompute();
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
