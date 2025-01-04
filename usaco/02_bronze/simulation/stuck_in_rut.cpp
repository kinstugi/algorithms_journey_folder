#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

struct Cow{
    int r, c, idx;
};


int main(){
    int n;
    cin >> n;
    
    vector<Cow> n_cows, e_cows;

    for (int i = 0; i < n; ++i){
        int r, c;
        char dxn;
        cin >> dxn >> r >> c;

        if (dxn == 'N'){
            n_cows.push_back({r, c, i});
        }else{
            e_cows.push_back({r, c, i});
        }
    }

    sort(n_cows.begin(), n_cows.end(), [&](const Cow &a, const Cow &b){ return a.r < b.r;});
    sort(e_cows.begin(), e_cows.end(), [&](const Cow &a, const Cow &b){ return a.c < b.c;});

    vector<int> stop_pos(n, -1);
    for(const Cow &ncow: n_cows){
        for(const Cow &ecow: e_cows){
            if (ncow.r > ecow.r && ncow.c < ecow.c){
                int e_trav = ncow.r - ecow.r;
                int n_trav = ecow.c - ncow.c;

                if (n_trav < e_trav && stop_pos[ecow.idx] == -1)
                stop_pos[ecow.idx] = ncow.r;

                if (n_trav > e_trav && stop_pos[ecow.idx] == -1){
                    stop_pos[ncow.idx] = ecow.c;
                    break;
                }
            }
        }
    }

    vector<int> dist(n, -1);
    for (const Cow &nCow: n_cows){
        if (stop_pos[nCow.idx] != -1){
            dist[nCow.idx] = stop_pos[nCow.idx] - nCow.c;
        }
    }

    for (const Cow &eCow: e_cows){
        if (stop_pos[eCow.idx] != -1){
            dist[eCow.idx] = stop_pos[eCow.idx] - eCow.r;
        }
    }

    for (int d : dist) {
		cout << (d == -1 ? "Infinity" : to_string(d)) << '\n';
	}
    return 0;
}