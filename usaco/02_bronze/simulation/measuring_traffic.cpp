#include <bits/stdc++.h>
using namespace std;

struct Rate {
    int lo, hi;
    string ramp;
};

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    setIO("traffic");
    int n;
    cin >> n;

    vector<Rate> rates(n);
    for (int i = 0; i < n; ++i)
    cin >> rates[i].ramp >> rates[i].lo >> rates[i].hi;

    int cur_lo = -9999, cur_hi = 9999;
    for (int i = n - 1; i >= 0; --i){
        if (rates[i].ramp == "none"){
            cur_lo = max(cur_lo, rates[i].lo);
            cur_hi = min(cur_hi, rates[i].hi);
        }else if (rates[i].ramp == "on"){
            cur_lo -= rates[i].hi;
            cur_hi -= rates[i].lo;
        }else{
            cur_lo += rates[i].lo;
            cur_hi += rates[i].hi;
        }
    }
   
    cout << max(0, cur_lo) << " " << cur_hi << "\n";

    cur_lo = -9999; cur_hi = 9999;
    for (int i = 0; i < n; ++i){
        if (rates[i].ramp == "none"){
            cur_lo = max(cur_lo, rates[i].lo);
            cur_hi = min(cur_hi, rates[i].hi);
        }else if (rates[i].ramp == "off"){
            cur_lo -= rates[i].hi;
            cur_hi -= rates[i].lo;
        }else{
            cur_lo += rates[i].lo;
            cur_hi += rates[i].hi;
        } 
    }
    cout << max(0, cur_lo) << " " << cur_hi << "\n";
    return 0;
}