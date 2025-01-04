#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    setIO("diamond");
    int n, k;
    cin >> n >> k;
    vector<int> diamonds(n);

    for (int i = 0; i < n; i++) { cin >> diamonds[i]; }
    sort(diamonds.begin(), diamonds.end());

    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if (diamonds[j] - diamonds[i] > k) break;
            ans = max(ans, j - i + 1);
        }
    }
    cout << ans << endl;
    return 0;
}