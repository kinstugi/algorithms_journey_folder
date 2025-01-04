#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    setIO("guess");
    int n, cnt; 

    cin >> n;
    string animal, xtic;
    map<string, set<string>> table;

    for (int i = 0; i < n; i++){
        cin >> animal >> cnt;
        for (int c = 0; c < cnt; c++){
            cin >> xtic;
            table[animal].insert(xtic);
        }
    }
    int ans = 0;
    for (auto &item: table){
        int d = 0;
        for (auto &item2: table){
            if (item.first == item2.first) continue;
            int dd = 0;
            for (string chr: item.second){
                if (item2.second.count(chr)){
                    dd++;
                    continue;
                }
            }
            d = max(d, dd);
        }
        ans = max(ans, d);
    }
    cout << (ans + 1) << endl;
    return 0;
}