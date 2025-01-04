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
    setIO();
    int num_jury, num_scores;
    cin >> num_jury >> num_scores;
    vector<ll> prefix(num_jury+1), scores(num_scores);

    for (int i = 1; i <= num_jury; ++i){  
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
    } 

    for (int i = 0; i < num_scores; i++) { cin >> scores[i]; }

    set<ll> possible_start;
    for (int i = 1; i <= num_jury; i++){ possible_start.insert(scores.back() - prefix[i]); }
    
    int ans = 0;
    for(int start: possible_start){
        set<ll> p_set;
        for (int i = 1; i <= num_jury; i++) { p_set.insert(start + prefix[i]); }

        bool flag = true;
        for (int score: scores){
            if (p_set.count(score)){ continue; }
            flag = false;
            break;
        }

        if (flag) {ans++;}
    }
    cout << ans << endl;
    return 0;
}