#include <bits/stdc++.h>
using namespace std;

vector<string> res;
vector<bool> seen(10, false);
string txt;
map<char, int> mp;

void recur(string cur) {
    if (cur.size() == txt.size()){ 
        res.push_back(cur);
        return;
    }

    for (auto &item: mp){
        if (item.second < 1) continue;
        item.second -= 1;
        recur(cur + item.first);
        item.second += 1;
    }
}

int main(){
    cin >> txt;
    // i know i can use next permutatio
    for (char ch: txt){ mp[ch]++; }

    recur("");
    cout << res.size() << endl;
    for(string s: res){  cout << s << endl; }
    return 0;
}