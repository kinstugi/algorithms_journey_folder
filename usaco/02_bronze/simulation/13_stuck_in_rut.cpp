#include <bits/stdc++.h>
using namespace std;

struct Cow{
    int x, y, idx;
};

int main(){
    int n, row, col;
    char dxn;
    cin >> n;

    vector<Cow> north_cows, east_cows;
    for (int i = 0; i < n; i++){
        cin >> dxn >> row >> col;

        if (dxn == 'N') { north_cows.push_back(Cow{row, col, i}); }
        else { east_cows.push_back({row, col, i}); }
    }

    sort(north_cows.begin(), north_cows.end(), [](Cow &a, Cow &b){ return a.x < b.x; });
    sort(east_cows.begin(), east_cows.end(), [](Cow &a, Cow &b){ return a.y < b.y; });

    vector<int> stop_pos(n, -1);
    for (const Cow &n_cow : north_cows){
        for (const Cow &e_cow: east_cows){
            if (n_cow.x > e_cow.x && e_cow.y > n_cow.y){
                int e_trav = n_cow.x - e_cow.x;
                int n_trav = e_cow.y - n_cow.y;

                if (n_trav < e_trav && stop_pos[e_cow.idx] == -1) { stop_pos[e_cow.idx] = n_cow.x;  }

                if (n_trav > e_trav && stop_pos[e_cow.idx] == -1){
                    stop_pos[n_cow.idx] = e_cow.y;
                    break;
                }
            }
        }
    }

    vector<int> dist(n, -1);
    for (const Cow &nCow: north_cows){
        if (stop_pos[nCow.idx] != -1){
            dist[nCow.idx] = stop_pos[nCow.idx] - nCow.y;
        }
    }

    for (const Cow &eCow: east_cows){
        if (stop_pos[eCow.idx] != -1){
            dist[eCow.idx] = stop_pos[eCow.idx] - eCow.x;
        }
    }

    for (int d : dist) {
		cout << (d == -1 ? "Infinity" : to_string(d)) << '\n';
	}
    return 0;
}