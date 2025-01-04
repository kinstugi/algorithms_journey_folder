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

const int mod = 7;

int main(){
    setIO("div7");
    int num_cows;
    cin >> num_cows;

    int ans = 0, cow; 
    int total = 0;

    map<int, int> mp;
    mp[0] = -1;

    for (int i = 0; i  < num_cows; i++){
        cin >> cow;
        total = ((total % mod) + (cow % mod)) % mod;
        
        if (mp.find(total) != mp.end()){
            ans = max(ans, i - mp[total]);
        }else{
            mp[total] = i;
        }
    }

    cout << ans << endl;
    return 0;
}