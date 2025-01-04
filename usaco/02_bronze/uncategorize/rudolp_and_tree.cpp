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
    // setIO("test");
    int t, n, base, height;
    cin >> t;
    
    while(t--){

        cin >> n >> base >> height;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) { cin >> arr[i]; }

        sort(arr.begin(), arr.end());
        double slope = base / (double)height;
        double ans = (double)base * height / 2.0;
        
        for (int i = 0; i < n-1; i++){
            if (arr[i]+height >= arr[i+1]){
                double height_dif = arr[i] + height - arr[i+1];

                double d1 = slope * height_dif;
                ans += (double) (base + d1) * (height - height_dif) / 2.0;
            }else{
                ans += (double)base * height / 2.0;
            }
        }
        cout << std::setprecision(17) << ans << "\n";
    }

    return 0;
}