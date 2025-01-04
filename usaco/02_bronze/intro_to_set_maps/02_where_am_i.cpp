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
    setIO("whereami");
    int n;
    cin >> n;
    string mailboxes;
    cin >> mailboxes;

    for (int k = 1; k <= n; k++){
        map<string, int> mp;
        bool flag = true;

        for (int i = 0; i <= n-k; i++){
            string sub = mailboxes.substr(i, k);
            //cout << sub << " ";
            if (mp.count(sub)){
                flag = false;
                // break;
            }
            mp[sub] = 1;
        }
    
        if (flag){
            cout << k << endl;
            return 0;
        }
    }
    return 0;
}