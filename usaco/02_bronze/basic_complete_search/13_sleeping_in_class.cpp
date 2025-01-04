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
    int T, n;
    cin >> T;
    
    while (T--){
        cin >> n;
        ll total = 0;
        vector<ll> arr(n);

        for (int i = 0; i < n; i++) { 
            cin >> arr[i];
            total += arr[i]; 
        }

        for (ll fact = 0; fact <= total; fact++){
            if (fact != 0 && total % fact != 0) { continue; }

            ll cur_tot = 0;
            bool flag = true;

            for (ll num: arr){
                cur_tot += num;
                if(cur_tot > fact){
                    flag = false;
                    break;
                }else if(cur_tot == fact){
                    cur_tot = 0;
                }
            }

            if (flag){
                if (fact == 0){
                    cout << 0 << endl;
                }else{
                    cout << n - total / fact << endl;
                    break;
                }
            }
        }
    }

    return 0;
}