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

int arr[101];

int main() {
	setIO();
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    cin >> arr[i];

    int mn = arr[0], mx = arr[0];
    int mnId = 0, mxId = 0;

    for (int i = 0; i < n; ++i){
        if (mx < arr[i]){
            mx = arr[i];
            mxId = i;
        }

        if (mn >= arr[i]){
            mn = arr[i];
            mnId = i;
        }
    }
    int res = mxId + (n-1-mnId);
    if (mxId > mnId)
    res -= 1;
    cout << res << '\n';
}