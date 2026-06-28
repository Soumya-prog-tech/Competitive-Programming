//  B. Omkar and Last Class of Math

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    int n;
    cin>>n;
    vector<int> divisors;
    for(int i = 2; i*i<=n; i++) {
        if (n%i==0) {
            divisors.push_back(i);
            if (i*i!=n) divisors.push_back(n/i);
        }
    }
    int min_lcm = n-1;
    vector<int> v = {1, n-1};
    for (const auto& x : divisors) {
        if (lcm(x, n-x) < min_lcm) {
            min_lcm = lcm(x, n-x);
            v = {x, n-x};
        }
    }
    cout<<v[0]<<" "<<v[1]<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
