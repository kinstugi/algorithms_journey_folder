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
	setIO("billboard");
    int ax1, ay1, ax2, ay2;
    int bx1, by1, bx2, by2;
    int cx1, cy1, cx2, cy2;

    cin >> ax1 >> ay1 >> ax2 >> ay2;
    cin >> bx1 >> by1 >> bx2 >> by2;
    cin >> cx1 >> cy1 >> cx2 >> cy2;

    int dx1 = max(ax1, cx1), dy1 = max(ay1, cy1);
    int dx2 = min(ax2, cx2), dy2 = min(ay2, cy2);

    int ans = getArea(ax1, ay1, ax2, ay2) + getArea(bx1, by1, bx2, by2);
    ans -= getArea(dx1, dy1, dx2, dy2);

    dx1 = max(cx1, bx1), dy1 = max(cy1, by1);
    dx2 = min(cx2, bx2), dy2 = min(cy2, by2);
    ans -= getArea(dx1, dy1, dx2, dy2);
    
    cout << ans << '\n';
}