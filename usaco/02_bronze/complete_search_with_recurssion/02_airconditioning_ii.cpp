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

struct Aircondition{
    int start, end, price, temp;
};

int main(){
    setIO();

    int num_cows, num_aircons, c_start, c_end, c_tmp;
    cin >> num_cows >> num_aircons;

    vector<int> stalls(101, 0);
    for (int i = 0; i < num_cows; i++){  
        cin >> c_start >> c_end >> c_tmp;

        for (int k = c_start; k <= c_end; k++) { stalls[k] = c_tmp; }
    }

    vector<Aircondition> airconditions(num_aircons);
    for (int i = 0; i < num_aircons; i++){
        cin >> airconditions[i].start >> airconditions[i].end >> airconditions[i].temp >> airconditions[i].price;
    }

    int ans = INT_MAX, bnd = 1 << num_aircons;

    for (int mask = 0; mask < bnd; mask++){
        vector<int> stalls_copy(stalls.begin(), stalls.end());
        int cur = 0;

        for (int k = 0; k < num_aircons; k++){
            int res = mask & (1 << k);

            if (!res) continue;

            for (int i = airconditions[k].start; i <= airconditions[k].end; i++){
                stalls_copy[i] -= airconditions[k].temp;
            }
            cur += airconditions[k].price;
            
        }

        bool flag = true;

        for (int stall: stalls_copy){
            if (stall > 0){
                flag = false;
                break;
            }
        }

        if (flag){
            ans = min(ans, cur);
        }
    }
    cout << ans << endl;
    return 0;
}