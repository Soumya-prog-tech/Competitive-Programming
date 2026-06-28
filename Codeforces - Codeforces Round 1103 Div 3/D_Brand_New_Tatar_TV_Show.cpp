#include <iostream>
#include <map>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    bool egor_wins = false;
    int prev_val = -1;

    for (auto const& [val, count] : freq) {
        // Condition 1: An even frequency guarantees a win state
        if (count % 2 == 0) {
            egor_wins = true;
            break;
        }

        // Condition 2: A valid jump between two DISTINCT elements guarantees a win state
        if (prev_val != -1 && val - prev_val <= k) {
            egor_wins = true;
            break;
        }

        prev_val = val;
    }

    if (egor_wins) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}