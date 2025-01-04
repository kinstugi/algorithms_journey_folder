#include <bits/stdc++.h>
using namespace std;

string zodiacs[12] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
map<string, int> z_map;

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
    map<string, int> cows_age;
    map<string, string> cows_zodiac;
    cows_age["Bessie"] = 100;
    cows_zodiac["Bessie"] = "Ox";

    for (int i = 0; i < 12; i++) { z_map[zodiacs[i]] = i; }

    int n; cin >> n;
    string cowA, cowB, tmp, zod, rel;
    for (int i = 0; i < n; i++){
        cin >> cowA >> tmp >> tmp >> rel >> zod >> tmp >> tmp >> cowB;

        cows_zodiac[cowA] = zod;
        int dxn = rel == "previous" ? -1 : 1;
        int startIdx = z_map[cows_zodiac[cowB]];
        int cnt = 0;

        do{
            startIdx += dxn;
            cnt++;
            if (startIdx < 0) { startIdx = 11; }
            if (startIdx >= 12) { startIdx = 0; }
        }while(zodiacs[startIdx] != zod);

        if (rel == "next"){cnt *= -1; }
        cows_age[cowA] = cows_age[cowB] + cnt;
    }
    cout << abs(cows_age["Bessie"] - cows_age["Elsie"]) << endl;
    return 0;
}