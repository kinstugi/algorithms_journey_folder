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

void lowerCase(string &txt){
    for(int i = 0; i < sz(txt); ++i){
        if ('a' <= txt[i] && txt[i] <= 'z') continue;
        txt[i] = txt[i] - 'A' + 'a';
    }
}

int main() {
	setIO();
    string a, b;
    cin >> a >> b;

    lowerCase(a);
    lowerCase(b);

    if (a == b)
    cout << "0\n";
    else if (a < b)
    cout << "-1\n";
    else
    cout << "1\n";
}