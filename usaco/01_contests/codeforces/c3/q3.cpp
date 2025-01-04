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

void solve(int n){
   
    vector<int> arr(n);
    for (int i = 0; i < n; i++) { cin >> arr[i]; }
    int l = 0, r = n -1;

    while (l < r){
        if (arr[l] != arr[l+1]) {  l++; r--; continue; }
        if (arr[l] != arr[r] && arr[r]){}
    }
}

int main(){
    setIO();
    int t, n;
    cin >> t;

    while (t--){
        cin >> n;
        solve(n);
    }
    return 0;
}