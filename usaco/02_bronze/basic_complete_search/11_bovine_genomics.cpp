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
    setIO("cownomics");
    int num_cows, gene_size;
    cin >> num_cows >> gene_size;

    vector<string> spotty_cows(num_cows), plain_cows(num_cows);
    for (int i = 0; i < num_cows; i++) { cin >> spotty_cows[i]; }
    for (int i = 0; i < num_cows; i++) { cin >> plain_cows[i]; }

    int ans = 0;
    for (int i = 0; i < gene_size; i++){
        for (int j = i+1; j < gene_size; j++){
            for (int k = j+1; k < gene_size; k++){
                
                set<string> mp;
                for(int c = 0; c < num_cows; c++){
                    string tmp = "";
                    tmp.push_back(spotty_cows[c][i]); tmp.push_back(spotty_cows[c][j]); tmp.push_back(spotty_cows[c][k]);
                    
                    mp.insert(tmp);
                }

                bool flag = true;
                for (int c = 0; c < num_cows; c++){
                    string tmp = "";
                    tmp.push_back(plain_cows[c][i]); tmp.push_back(plain_cows[c][j]); tmp.push_back(plain_cows[c][k]);

                    if (mp.count(tmp)){ flag = false;  break; }
                }

                ans += flag;
            }
        }
    }
    cout << ans << endl;
    return 0;
}