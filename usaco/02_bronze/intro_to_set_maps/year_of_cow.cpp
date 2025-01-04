#include <bits/stdc++.h>
using namespace std;

const vector<string> ZODIAC{"Ox",      "Tiger", "Rabbit", "Dragon",
                            "Snake",   "Horse", "Goat",   "Monkey",
                            "Rooster", "Dog",   "Pig",    "Rat"};

struct Relation{
    string name;
    bool prev;
    int year;
    string relative;
};

int mod(int n, int m){ return ((n % m) + m) % m;}

int main(){
    int n;
    cin >> n;

    vector<Relation> relations(n);
    for(Relation &r: relations){
        string prev, animail, tmp;
        cin >> r.name >> tmp >> tmp >> prev >> animail >> tmp >> tmp >> r.relative;
        r.prev = prev == "previous";
        r.year = find(ZODIAC.begin(), ZODIAC.end(), animail) - ZODIAC.begin();
    }

    unordered_map<string, int> cows{{"Bessie", 0}};
    
    for (Relation r: relations){
        int change = r.prev ? -1 : 1;
        int year = cows[r.relative] + change;
        while (mod(year, ZODIAC.size()) != r.year){ year += change; }
        cows[r.name] = year;
    }

    cout << abs(cows["Elsie"]) << "\n";
    return 0;
}