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
    setIO("badmilk");
    int num_guests, num_milk, num_records, num_sick;
    cin >> num_guests >> num_milk >> num_records >> num_sick;

    map<int, set<int>> tables[num_guests + 1];
    map<int, set<int>> tally;
    int person, milk, time_taken;

    for (int i = 0; i < num_records; i++){
        cin >> person >> milk >> time_taken;
        tables[person][time_taken].insert(milk);
        tally[milk].insert(person);
    }

    map<int, int> freq;
    for (int i = 0; i < num_sick; i++){
        cin >> person >> time_taken;
        set<int> milks;

        for (auto &item: tables[person]){
            if (item.first < time_taken){
                for (int t: item.second) { milks.insert(t); }
            }
        }

        for (int t: milks){ freq[t]++; }
    }

    int spoiled_milked = -1, cnt = 0;
    for (auto &item: freq){
        if (cnt < item.second){
            cnt = item.second;
            spoiled_milked = item.first;
        }
    }

    cout << tally[spoiled_milked].size() << endl;
    return 0;
}