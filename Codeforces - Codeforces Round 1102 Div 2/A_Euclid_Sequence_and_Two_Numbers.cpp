//  A. Euclid, Sequence and Two Numbers

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    int n;
    cin>>n;
    vector<int> b(n);
    for (int i = 0; i<n; i++) {
        cin>>b[i];
    }
    sort(b.begin(), b.end(), greater<int>());
    for (int i = 2; i<n; i++) {

        if (b[i] != (b[i-2] % b[i-1])) {
           cout<<-1<<endl;
            return;
        }
    }
    cout<<b[0]<<" "<<b[1]<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
