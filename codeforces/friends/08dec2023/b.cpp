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
int p1[60], p2[60];

int main() {
	setIO();
	int t, n, k, q, cnt, tmp; 
    cin >> t;
    
    while(t--){
        cin >> n >> k >> q;
        cnt = 0;
        for (int i = 0; i < n; ++i){
            cin >> tmp;
            if (tmp <= q) cnt++;
        }
        int mx = 0, mn = 0;
        mx = cnt * (cnt - 1) * 0.5;
        mn = (k-1) * (k-2) * 0.5;
        cout << mx - mn << '\n';
    }
}