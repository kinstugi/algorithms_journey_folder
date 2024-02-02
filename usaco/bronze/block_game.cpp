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

int res[26];

int main() {
	setIO("blocks");
	int n; cin >> n;
    string a, b;
    vector<int> tmpA(26, 0), tmpB(26, 0);
    while(n--){
        cin >> a >> b;
        for (int i = 0; i < 26; ++i)
        tmpA[i] = 0, tmpB[i] = 0;

        for (char ch: a)
        tmpA[ch-'a']++;
        
        for(char ch: b)
        tmpB[ch-'a']++;
        
        for (int i = 0; i < 26; ++i)
        res[i] += max(tmpA[i], tmpB[i]);
    }

    for (int i = 0; i < 26; ++i)
    cout << res[i] << '\n';
}