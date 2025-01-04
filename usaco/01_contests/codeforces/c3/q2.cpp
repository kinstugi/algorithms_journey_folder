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