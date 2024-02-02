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

void helper(int &a, int &b, int &bucket){
	if (a + b <= bucket){
		b += a;
		a = 0;
	}else{
		a -= bucket - b;
		b = bucket;
	}
}

int main() {
	setIO("mixmilk");
	int bucketA, a,  bucketB, b, bucketC, c;
	cin >> bucketA >> a;
	cin >> bucketB >> b;
	cin >> bucketC >> c;

	int cnt = 99;
	while (cnt){
		helper(a, b, bucketB);
		cnt--;
		helper(b, c, bucketC);
		cnt--;
		helper(c, a, bucketA);
		cnt--;
	}
	helper(a,b, bucketB);
	cout << a << "\n" << b << "\n" << c << "\n";
}