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

string cows[7] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};

int main(){
    setIO("notlast");
    int n; cin >> n;
    string cow; int milk;
    map<int, vector<string>> table;
    map<string, int> cows_milk_tally;
    for(string cow: cows){ cows_milk_tally[cow] = 0; }

    for (int i = 0; i < n; i++){
        cin >> cow >> milk;
        cows_milk_tally[cow] += milk;
    }

    for (string cow: cows){
        table[cows_milk_tally[cow]].push_back(cow);
    }

    if (table.size() < 2){
        cout << "Tie\n";
    }else{
        int rem = 1;
        for (const auto &item: table){
            if (rem == 0){
                if (item.second.size() > 1){ cout << "Tie\n"; }
                else { cout << item.second[0] << endl; }
                break;
            }
            rem--;
        }
    }

    return 0;
}