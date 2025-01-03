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

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
	setIO();
    int a, b, g;
    cin >> a >> b >> g;
    int i = 0;

    while (true){
        int rem = gcd(a, g);
        if (rem > g){
            cout << "1\n";
            break;
        }
        g -= rem;
        rem = gcd(b, g);
        if (rem > g){
            cout << "0\n";
            break;
        }
        g-= rem;
        i++;
    }
}