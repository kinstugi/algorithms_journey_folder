#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;

    int n = s.size(), cnt = 0;
    bool all = (s[0] == 'B' || s[n-1] == 'B');
    
    for (int i = 0; i < n-1; i++){
        if (s[i] == s[i+1] && s[i] == 'B') { all = true; }
    }

    vector<int> lens;
    int curr = 0;

    for (char ch: s){
        if (ch == 'A'){ curr++;}
        else { 
            if (curr)
            lens.push_back(curr);
            curr = 0;
        }
    }

    if (curr != 0) { lens.push_back(curr); }

    if (lens.empty()) {
        cout << 0 << endl; 
        return;
    }
    sort(lens.begin(), lens.end());
    int ans = 0;
    if (all) { ans = lens[0]; }

    for (int i = 1; i < lens.size(); i++){ ans += lens[i]; }
    cout << ans << endl;
    
}

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    // setIO("test");
    int t;
    cin >> t;

    while (t--) { solve(); }
    return 0;
}