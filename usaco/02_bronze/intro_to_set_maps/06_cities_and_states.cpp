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

int main(){
    setIO("citystate");
    int n;
    cin >> n;

    vector<pair<string, string>> cities(n);
    map<string, vector<string>> states;

    for (int i = 0; i < n; i++){
        cin >> cities[i].first >> cities[i].second;
        states[cities[i].second].push_back(cities[i].first);
    }

    int ans = 0;
    for (const auto &city: cities){
        string city_initial = city.first.substr(0, 2);
        for(char &ch: city_initial){
            ch = toupper(ch);
        }

        if (states.count(city_initial) && city_initial != city.second){
            for (string cc: states[city_initial]){
                string initial = cc.substr(0,2);
                for (char &ch: initial){ ch = toupper(ch); }
                if (initial == city.second){ans++;}
            }
        }
    }
    cout << (ans/2) << endl;
    return 0;
}