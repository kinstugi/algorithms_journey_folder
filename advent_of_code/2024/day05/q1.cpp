#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void setIO(string file= ""){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (!file.empty()){
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}

int getWeight(int nd, map<int, vector<int>> &edges, map<int, int> &ranks, set<int> &seen){
    if (seen.count(nd)) return ranks[nd];
    int rk = (int)edges[nd].size();
    for (int sub: edges[nd]){
        rk += getWeight(sub, edges, ranks, seen);
    }
    seen.insert(nd);
    ranks[nd] = rk;
    return rk;
}

int main(){
    setIO("input");
    map<int, vector<int>> edges;
    map<int, int> ranks;
    set<int> seen;

    string s;
    int a, b;

    while(getline(cin ,s)){
        if (s.empty() || !isdigit(s[0])) break;
        istringstream iss(s);
        iss >> a >> b;
        edges[a].push_back(b);   
    }
    for (auto item: edges){
        getWeight(item.first, edges, ranks, seen);
    }
    
    for (auto item: ranks){  
        cout << item.first << " -> " << item.second << endl;
    }
    return 0;
}