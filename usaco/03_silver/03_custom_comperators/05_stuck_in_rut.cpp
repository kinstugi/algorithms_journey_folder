#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void setIO(string file_name = ""){
    ios_base::sync_with_stdio();
    cin.tie(0);

    if (file_name.size()){
        freopen((file_name + ".in").c_str(), "r", stdin);
        freopen((file_name + ".out").c_str(), "w", stdout);
    }
}

struct Cow{
    int x, y, id;
};

int main(){
    setIO();
    vector<Cow> n_cows, e_cows;
    int n, row, col;
    char dxn;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> dxn >> row >> col;
        if (dxn == 'E'){
            e_cows.push_back({row, col, i});
        }else { 
            n_cows.push_back({row, col, i});
        }
    }

    sort(n_cows.begin(), n_cows.end(), [](Cow &a, Cow &b){ return a.x < b.x; });
    sort(e_cows.begin(), e_cows.end(), [](Cow &a, Cow &b){ return a.y < b.y; });

    
    return 0;
}