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
const int mx_size = 200001;
int arr1[mx_size], arr2[mx_size], arr3[mx_size];

int main() {
	setIO();
	int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    cin >> arr1[i];

    for (int i = 0; i < n; ++i)
    cin >> arr2[i];

    for (int i = 0; i < n; ++i)
    arr3[i] = arr1[i] - arr2[i];

    sort(arr3, arr3 + n);
    ll  ans = 0;
    for (int i = 0; i < n; ++i){
        if (arr3[i] <= 0) continue;
        int idx = lower_bound(arr3, arr3+n, 1-arr3[i]) - arr3;
        ans += i - idx;
    }
    cout << ans << endl;
}