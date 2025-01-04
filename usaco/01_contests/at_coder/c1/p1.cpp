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

int main(){
    setIO();
    int n; cin >> n;
    string s;
    cin >> s;
    int ans = 0;


    for (int i = 1; i < n-1; i++){
        if (s[i] == '.' && s[i-1] == '#' && s[i+1] == '#') { ans++; }
    }

    cout << ans << endl;
    return 0;
}