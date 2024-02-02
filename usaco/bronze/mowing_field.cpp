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

map<pi, int> memo;

int main() {
	setIO("mowing");
    int n, d, ans = 9999999;
    char dxn;
    cin >> n;
    int x = 0, y = 0, t = 0;
    // cout << x << " " << y << " " << t<<"\n";
    memo[mp(x, y)] = t;
    while (n--){
        
        cin >> dxn >> d;
        for (int i = 0; i < d; ++i){
            t++;
            if (dxn == 'N')
            x -= 1;
            else if (dxn == 'S')
            x += 1;
            else if (dxn == 'W')
            y -= 1;
            else
            y += 1;

            if (memo.count({x, y}))
            ans = min(ans, t - memo[{x, y}]);
        //    cout << x << " " << y << " " << t<<"\n";
            memo[{x, y}] = t;
        }
    }
    if (ans == 9999999)
    cout << -1 << '\n';
    else
    cout << ans << "\n";
}