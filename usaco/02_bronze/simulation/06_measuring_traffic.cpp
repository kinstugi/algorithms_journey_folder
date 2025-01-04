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

struct Traffic{
    string ramp;
    int maxTraffic, minTraffic;
};

int main(){
    setIO("traffic");
    int n;
    cin >> n;

    vector<Traffic> trafficData(n);

    for (int i = 0; i < n; i++) {  cin >> trafficData[i].ramp >> trafficData[i].minTraffic >> trafficData[i].maxTraffic; }

    int mn = -9999, mx = 9999;
    for (int i = n - 1; i > -1; i--){
        
        if (trafficData[i].ramp == "off") {
            mn += trafficData[i].minTraffic; mx += trafficData[i].maxTraffic;
        }
        else if (trafficData[i].ramp == "none") { mn = max(mn, trafficData[i].minTraffic); mx = min(mx, trafficData[i].maxTraffic); }
        else {
            mn -= trafficData[i].maxTraffic; mx -= trafficData[i].minTraffic;
        }
    }
    cout << max(0, mn) << " " << mx << endl;

    mn = -9999, mx = 9999;

    for (int i = 0; i < n; i++){
        if (trafficData[i].ramp == "on") {
            mn += trafficData[i].minTraffic; mx += trafficData[i].maxTraffic;
        }else if (trafficData[i].ramp == "none") { mn = max(mn, trafficData[i].minTraffic); mx = min(mx, trafficData[i].maxTraffic); }
        else {
            mn -= trafficData[i].maxTraffic; mx -= trafficData[i].minTraffic;
        }
    }
    cout << max(mn, 0) << " " << mx << endl;
    return 0;
}