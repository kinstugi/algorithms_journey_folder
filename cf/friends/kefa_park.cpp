#include <bits/stdc++.h> 
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

const int N = 2e5 + 1;
int cats[N], seen[N];
int n, m, a, b, ans = 0;
vi graph[N];

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0);
	if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin); 
		freopen((name+".out").c_str(), "w", stdout);
	}
}

void helper(int node, int cc){
	bool isLeaf = true;

	for (int nei: graph[node]){
		if (seen[nei]) continue;
		seen[nei] = 1;
		isLeaf = false;
		int nxt = cats[nei] ? cc + 1 : 0;
		if (nxt > m) continue;
		helper(nei, nxt);
	}

	if (!isLeaf) return;
	if (cc <= m)
		ans++;
}

int main() {
	setIO("");
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		cin >> cats[i], seen[i] = 0;

	for(int i = 1; i < n; ++i){
		cin >> a >> b;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	seen[1] = 1;
	helper(1, cats[1]);
	cout << ans << "\n";
	return 0;
}