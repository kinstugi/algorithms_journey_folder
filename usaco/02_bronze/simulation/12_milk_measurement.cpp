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

struct Record{
    string cow;
    int day, dt;
    bool operator<(Record &other){
        return day < other.day;
    }
};

int main(){
    setIO("measurement");
    int n;
    cin >> n;
    int  tally[3] = {7, 7, 7}, cur_mx = 7, ans = 0;
    map<string, int> mp = {{"Elsie", 0}, {"Bessie", 1}, {"Mildred", 2}};
    string cur_pic = "ebm";

    vector<Record> records(n);
    for (int i = 0; i < n; i++) { cin >> records[i].day >> records[i].cow >> records[i].dt; }

    sort(records.begin(), records.end());
    
    for (const Record &record: records){
        tally[mp[record.cow]] += record.dt;
        int new_max = INT32_MIN;
        for (int num: tally){ new_max = max(num, new_max); }
        string new_pic = "";
        if (tally[mp["Elsie"]] == new_max) { new_pic.push_back('e'); }
        if (tally[mp["Bessie"]] == new_max) { new_pic.push_back('b'); }
        if (tally[mp["Mildred"]] == new_max) { new_pic.push_back('m'); }
        
        if (new_pic != cur_pic){
            cur_pic = new_pic;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}