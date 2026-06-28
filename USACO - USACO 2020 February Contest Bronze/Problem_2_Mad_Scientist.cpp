//  Problem 2. Mad Scientist

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    int n;
    cin>>n;
    string a;
    cin>>a;
    string b;
    cin>>b;
    int i = 0;
    int count = 0;
    while (i<n) {
        if (a[i] == b[i]) {
            i++;
            continue;
        }
        else {
            count++;
            while (i<n && a[i] != b[i]) i++;
        }
    }
    cout<<count<<endl;
}

int main() {
    int t = 1;
    // cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
