//  B. Value of an Expression

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

const int MAXA = 1e6+1;
int prime_factor[MAXA];

void precompute() {
    for (int i = 2; i<MAXA; i++) {
        if (prime_factor[i] == 0) {
            for (int j = i; j<MAXA; j+=i) {
                prime_factor[j]++;
            }
        }
    }
}

void solve() {
    int n, x;
    cin>>x>>n;
    vector<int> v(n);
    for (int i = 0; i<n; i++) {
        cin>>v[i];
    }
    precompute();
    deque<int> dq;
    int ans = INT_MAX;
    for (int i = 0; i<n; i++) {
        if (!dq.empty() && dq.front() == i - x) {
            dq.pop_front();
        }
        while (!dq.empty() && prime_factor[v[dq.back()]] <= prime_factor[v[i]]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i>=x-1) {
            ans = min(ans, v[dq.front()]);
        }
    }
    cout<<ans<<endl;
}

int main() {
    int t = 1;
    // cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
