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
    int day, delta;
    string cow;

    bool operator<(Record &other){
        return day < other.day;
    }
};

int main(){ 
    setIO("measurement");
    int n;
    cin >> n;
    vector<Record> records(n);

    for (int i = 0; i < n; ++i)
    cin >> records[i].day >> records[i].cow >> records[i].delta;
    
    sort(records.begin(),  records.end());
    
    int bessie = 7,  mildred = 7, elsie = 7;
    string leader = "bme";
    int ans = 0;

    for (Record record: records){
        if (record.cow == "Mildred")
        mildred += record.delta;
        else if (record.cow == "Elsie")
        elsie += record.delta;
        else
        bessie += record.delta; 

        // set the new leader
        string newLeader = "";
        int mx = max(bessie, max(elsie, mildred));

        if (bessie == mx)
        newLeader.append("b");
        if (mildred == mx)
        newLeader.append("m");
        if (elsie == mx)
        newLeader.append("e");

        if (leader != newLeader){
            leader = newLeader;
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}