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
int p1[60], p2[60];

int main() {
	setIO();
	int t, n, m; 
    cin >> t;
    
    while(t--){
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
        cin >> p1[i];

        for (int i = 0; i < m; ++i)
        cin >> p2[i];

        sort(p1, p1 + n);
        sort(p2, p2 + m);

        int p1_l = 0, p1_r = n-1;
        int p2_l = 0, p2_r = m-1;

        int i = 0;
        while (p1_l <= p1_r && p2_l <= p2_r){
            if (i % 2){
                p1[p1_r] -= p2[p2_l];
                p2[p2_l] -= p1[p1_r];
                if (p2[p2_l] <= 0)
                p2_l++;
                if (p1[p1_r] <= 0)
                p1_r--;
            }else{
                p1[p1_l] -= p2[p2_r];
                p2[p2_r] -= p1[p1_l];
                if (p2[p2_r] <= 0)
                p2_r--;
                if (p1[p1_l] <= 0)
                p1_l++;
            }
        }

        if (p1_l > p1_r && p2_l > p2_r)
        cout << "Draw\n";
        else if (p1_l > p1_r)
        cout << "Tenzing\n";
        else
        cout << "Tsondun\n";
    }
}