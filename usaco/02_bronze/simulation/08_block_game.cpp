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
    setIO("blocks");
    int n;
    cin >> n;
    string a, b;

    vector<int> mp(26), mp1(26), mp2(26); 

    while (n--){
        mp1.assign(26, 0); mp2.assign(26, 0);
        cin >> a >> b;
        for (char ch: a){ mp1[ch - 'a']++; }
        for (char ch: b){ mp2[ch - 'a']++; }

        
        for (int i = 0; i < 26; i++) { mp[i] += max(mp1[i], mp2[i]); }
    }
    for (int i = 0; i < 26; i++) { cout << mp[i] << endl; }
    return 0;
}