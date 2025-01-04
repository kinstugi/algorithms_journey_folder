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

void solve(){
	int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) { cin >> arr[i]; }
    
    vector<int> left(n), right(n);
    for (int i = 0; i < n; i++){
        left[i] = arr[i] + i;
        right[i] = arr[i] - i;
    }

    for (int i = 1, j = n - 2; i < n; i++, j--){
        left[i] = max(left[i], left[i-1]);
        right[j] = max(right[j], right[j+1]);
    }

    int ans = 0;
    for (int i = 1; i < n-1; i++) { ans = max(ans, left[i-1] + right[i+1] + arr[i]); }
    cout << ans << endl;
}

int main(){
    setIO("test");
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}