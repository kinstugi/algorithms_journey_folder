#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin); // see /general/io
		freopen((name+".out").c_str(), "w", stdout);
	}
}

int getArea(int x1, int y1, int x2, int y2){
    if (x1 > x2 || y1 > y2) return 0;
    return (x1-x2) * (y1- y2);
}

int main() {
	setIO("");
    int t; cin >> t;
    int ax1, ay1, ax2, ay2;
    int w, h, W, H;
    
    while (t--){

        cin >> W >> H;
        cin >> ax1 >> ay1 >> ax2 >> ay2;
        cin >> w >> h;

        int tw = ax2 - ax1, th = ay2 - ay1;
        if ((tw + w) > W && (th + h) > H){
            cout << -1 << '\n';
            continue;
        }
        int a = max(0, min(w - ax1, w - (W-ax2)));
        int b = max(0, min(h - ay1, h - (H-ay2)));

        if ((tw + w) > W){
            cout << b <<  '\n';
        }else if ((th + h) > H){
            cout << a << '\n';
        }else{
            int ans = min(a, b);
            if ((w <= ax1 || w <= (W-ax2)))
            cout << 0 << '\n';
            else if (h <= ay1 || h <= (H-ay2))
            cout << 0 << '\n';
            else
            cout << ans << '\n';
        }
       
    }

    return 0;
}