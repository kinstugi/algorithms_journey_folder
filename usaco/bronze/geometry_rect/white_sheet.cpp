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

struct Rectangle{
    int x1,  y1,  x2, y2;
    Rectangle(){}
    Rectangle(int x1_, int y1_, int x2_, int y2_){
        x1 = x1_; x2 = x2_; y1 = y1_; y2 = y2_;
    }
};

vi findIntersect(Rectangle &r1, Rectangle &r2){
    int x1 = max(r1.x1, r2.x1), y1 = max(r1.y1, r2.y1);
    int x2 = min(r1.x2, r2.x2), y2 = min(r1.y2, r2.y2);
    return {x1, y1, x2, y2};
}

int main() {
	setIO("");
    Rectangle whiteSheet,  black1, black2;

    cin >> whiteSheet.x1 >> whiteSheet.y1 >> whiteSheet.x2 >> whiteSheet.y2;
    cin >> black1.x1 >> black1.y1 >> black1.x2 >> black1.y2;
    cin >> black2.x1 >> black2.y1 >> black2.x2 >> black2.y2;
}