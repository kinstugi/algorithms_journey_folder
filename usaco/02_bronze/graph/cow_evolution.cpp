#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}


int main(){
    setIO("evolution");
    int n;
    cin >> n;

    vector<set<string>> cows;
    set<string> all_chars_set;

    for (int c = 0; c < n; c++){
        int a; string tmp;
        set<string> cur_cow;

        cin >> a;
        for (int i = 0; i < a; i++){
            cin >> tmp;
            cur_cow.insert(tmp);
        }
        all_chars_set.insert(cur_cow.begin(), cur_cow.end());
        cows.push_back(cur_cow);
    }

    vector<string> all_chars(all_chars_set.begin(), all_chars_set.end());
    
    return 0;
}