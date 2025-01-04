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
    setIO();
    
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);

    int mx = INT_MIN;
    for (int i = 0; i < n; i++) { 
        cin >> arr[i];
        mx = max(mx, arr[i]); 
    }

    if (m == 0){ 
        // all should be same then
        for (int i = 0; i < n; i++){ cout << mx << " "; }
        return 0;
    }

    for (int i = 1; i < n; i++){
        if (abs(arr[i] - arr[i-1]) <= m) continue;
        if (arr[i] < arr[i-1]) { arr[i] = arr[i-1] - m; }
        else{
            arr[i-1] = arr[i] - m;
        }
    }
    return 0;
}