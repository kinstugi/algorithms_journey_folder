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

int main() {
	setIO("shell");
	int n, a, b, g;
	int s1 = 0, s2 = 0, s3 = 0;
	int game1[] = {0,1,0,0}, game2[] = {0,0,1,0}, game3[] = {0,0,0,1};

	cin >> n;
	while (n--){
		cin >> a >> b >> g;
		swap(game1[a], game1[b]); s1 += game1[g];
		swap(game2[a], game2[b]); s2 += game2[g];
		swap(game3[a], game3[b]); s3 += game3[g];
	}
	cout << max({s1,s2,s3}) << endl;
}