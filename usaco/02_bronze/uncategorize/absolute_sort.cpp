#include <iostream>
using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int arr[200000];

int main(){
    //setIO();
    int t, n;
    cin >> t;

    while(t--){
        cin >> n;
        for (int i = 0; i < n; i++) { cin >> arr[i]; }

        int mn = 0, mx = int(1e9);
        for(int j = 0; j + 1 < n; j++)
        {
            int x = arr[j];
            int y = arr[j + 1];
            int midL = (x + y) / 2;
            int midR = (x + y + 1) / 2;
            if(x < y)
                mx = min(mx, midL);
            if(x > y)
                mn = max(mn, midR);
        }

        if (mn <= mx) cout << mn << endl;
        else cout << -1 << endl;
    }

    return 0;
}