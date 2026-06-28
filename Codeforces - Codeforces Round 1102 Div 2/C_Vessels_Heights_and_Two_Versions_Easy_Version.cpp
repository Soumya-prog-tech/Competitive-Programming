//  C. Vessels, Heights and Two Versions (Easy Version)

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    int n;
    cin>>n;
    vector<int> h(n);
    for (int i = 0; i<n; i++) {
        cin>>h[i];
    }
    for (int i = 0; i<n; i++) { // looping through all the empty vessels
        vector<int> w1(n);
        vector<int> w2(n);
        vector<int> w(n);
        for (int j = 1; j<n; j++) {
            w1[(i+j)%n] = max(w1[(i+j-1)%n],  h[(i+j-1)%n]);
        }
        for (int j = 1; j<n; j++) {
            w2[(i+n-j)%n] = max(w2[(i+n-j+1)%n], h[(i+n-j)%n]);
        }
        for (int j = 1; j<n; j++) {
            w[(i+j)%n] = min(w1[(i+j)%n], w2[(i+j)%n]);
        }
        cout<<accumulate(w.begin(), w.end(), 0LL)<<" ";
    }
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
