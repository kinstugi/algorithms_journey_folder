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

int solve(int x, int target){
    int prev = x, m = -1, cur, ans = 0;
    
    for (int i = 0; i < 16; ++i){
        cur = x  + (pow(2, i) * pow(m, i));
        if (prev > cur){
            while(prev != cur){
                if (prev == target) return ans;
                prev--;
                ans++;
            }
        }else{
            while(prev != cur){
                if (prev == target) return ans;
                prev++;
                ans++;
            }
        }
    }
    return ans;
}

int main() {
	setIO("lostcow");
	int x, y;
    
    cin >> x >> y;
    cout << solve(x, y) << '\n';
}