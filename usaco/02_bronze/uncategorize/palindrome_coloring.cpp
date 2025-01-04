#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    setIO("");
    int t, n, k;
    string s;

    vector<int> mp(26);
    cin >> t;
    while(t--){
        for (int i = 0; i < 26; i++) { mp[i] = 0;} //reseting the mp
        cin >> n >> k;
        cin >> s;

        for(char ch: s){ mp[ch - 'a']++; }

        int rem = 0, div = 0;
        for (int v: mp){
            rem += v % 2;
            div += v / 2;
        }
        int ans = (div / k) * 2;
        rem += (div % k) * 2;
        if (rem >= k) { ans += 1; }
        cout << ans << endl;
    }
    return 0;
}