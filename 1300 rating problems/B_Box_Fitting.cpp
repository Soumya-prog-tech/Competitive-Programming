//  B. Box Fitting

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    int n, W;
    cin>>n>>W;
    vector<int> a(n);
    vector<int> widthCount(21);
    for (int i = 0; i<n; i++) {
        cin>>a[i];
        int logVal = log2(a[i]);
        widthCount[logVal]++;
    }
    int countOfBoxes = 0;
    int height = 0;
    while (countOfBoxes<n) {
        int currentWidth = W;
        for (int i = 20; i>=0; i--) {
            while (widthCount[i] > 0 && (1<<i) <= currentWidth) {
                currentWidth -= (1<<i);
                widthCount[i]--;
                countOfBoxes++;
            }
        }
        height++;
    }
    cout<<height<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
