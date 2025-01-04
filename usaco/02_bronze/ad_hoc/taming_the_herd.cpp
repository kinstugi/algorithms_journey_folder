#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("taming");
    int n;
    cin >> n;

    vector<int> logs(n);
    for (int i = 0; i < n; ++i) {
        cin >> logs[i];
    }

    // Ensure the first day starts with a breakout
    if (logs[0] > 0) {
        cout << "-1\n";
        return 0;
    }
    logs[0] = 0;

    // Check consistency by backward propagating values
    for (int i = 0; i < n; ++i) {
        if (logs[i] != -1) {
            int expected = logs[i];
            for (int j = i; j >= 0 && expected >= 0; --j) {
                if (logs[j] == -1) {
                    logs[j] = expected;
                } else if (logs[j] != expected) {
                    cout << "-1\n";
                    return 0;
                }
                expected--;
            }
        }
    }

    int mn = 0, mx = 0;
    for (int i = 0; i < n; ++i) {
        if (logs[i] == 0) {
            mn++;
            mx++;
        } else if (logs[i] == -1) {
            mx++;
        }
    }

    cout << mn << " " << mx << "\n";
    return 0;
}
