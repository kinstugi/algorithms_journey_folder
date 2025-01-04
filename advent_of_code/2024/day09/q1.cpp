#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void setIO(string file = ""){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (!file.empty()){
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    }
}

int getDigitCount(int num){
    int cnt = 0;
    while (num){
        cnt++;
        num /= 10;
    }
    return cnt;
}

string getPacket(int pkSize, int content){
    string st = to_string(content);
    int rm = pkSize - st.length();
    string res;
    for (int i = 0; i < rm; i++){ res += '0'; }
    res += st;
    return res;
}

string parseToMem(string txt, int &chunkSize){
    int id = -1;
    for (int i = 0, len = txt.length(); i < len; i++){
        if (i % 2 == 0) { id++; }
    }
    int mxCnt = getDigitCount(id);
    id = -1;
    string res = "";
    for (int i = 0, len = txt.length(); i < len; i++){
        int cnt = txt[i] - '0'; 
        if (i % 2 == 0) {
            id++;
            while(cnt--){ res += getPacket(mxCnt, id) + ' '; }
        }else{
            while (cnt--){
                for (int k = 0; k < mxCnt; k++) { res += '.'; }
                res += ' ';
            }
        }
    }
    chunkSize = mxCnt;
    return res;
}

int main(){
    setIO("sample");
    string s;
    getline(cin, s);
    int chunkSize;
    string mem = parseToMem(s, chunkSize);
    
    int l = 0, r = mem.size() - chunkSize - 1;
    while (l < r){

        while (!isdigit(mem[r])){
            r -= (chunkSize + 1);
        }

        while (isdigit(mem[l])){
            l += (chunkSize + 1);
        }
        if (r <= l) break;

        // swap the chunks
        for (int i = 0; i < chunkSize; i++){
            swap(mem[l+i], mem[r+i]);
        }
        r -= (chunkSize + 1);
        l += (chunkSize + 1);
    }

    ll answer = 0;
    l = 0;
    int currentId = 0;

    while (mem[l] != '.'){
        int num = 0;
        for (int i = 0; i < chunkSize; i++){
            num = (num * 10) + (mem[l+i] - '0');
        }
        answer += (num * currentId);
        l += (chunkSize + 1);
        currentId++;
    }

    cout << answer << endl;
    return 0;
}