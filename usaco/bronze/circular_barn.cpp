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

int arr[1000];

int main() {
	setIO("cbarn");
	int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    cin >> arr[i];

    int ans = INT_MAX;
    for (int i = 0; i < n; ++i){
        int tot = 0;
        for (int k = 0; k < n; ++k){
            tot += arr[(i+k) % n] * k;
        }
        ans = min(ans, tot);
    }
    cout << ans << '\n';
}