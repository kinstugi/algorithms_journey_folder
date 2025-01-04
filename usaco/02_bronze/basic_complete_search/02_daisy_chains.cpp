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
    int n;
    cin >> n;

    vector<int> flowers(n+1), prefix(n+1);
    for (int i = 1; i <= n; i++ ) { 
        cin >> flowers[i];
        prefix[i] = prefix[i-1] + flowers[i]; 
    }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            
            int tot = prefix[j] - prefix[i-1], cnt = j - i + 1;
            double avg = (double) tot / cnt;
            
            for (int x = i; x <= j; x++) { 
                if (flowers[x] == avg){
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}