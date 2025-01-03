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

int arr[26];

int main() {
	setIO();
    string guest, host, scram;
    cin >> guest >> host >> scram;

    for (char ch: scram)
    arr[ch - 'A']++;

    for (char ch: guest)
    arr[ch - 'A']--;

    for (char ch: host)
    arr[ch - 'A']--;

    bool flag = true;
    for (int i = 0; i < 26; ++i){
        if (arr[i] != 0){
            flag = false;
            break;
        }
    }

    if (flag)
    cout << "Yes\n";
    else
    cout << "No\n";
}