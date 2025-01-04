#include<bits/stdc++.h>
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
        cnt++; num /= 10;     
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

int findSpaceFromLeft(int idx, int targetSize, const string &mem){
    int len = mem.length();
    
    for (int i = idx; i < len; i++){
        if (mem[i] != '.') continue;
        int end = i;

        while (end < len){
            int nxt = end + 1;
            char nextChar = nxt < len ? mem[nxt] : ' ';
            if (mem[end] == '_' && nextChar == ' '){ break; }
            end = nxt;
        }
        if (targetSize <= end - i + 1){return i;}
        //spaceSize = end - i + 1;
        i = end;
    }
    return -1;
}

int findFileFromRight(int idx, int &fileSize, const string &mem){ 
    int cnt = 0; 
    while(idx >= 0){ 
        int nxt = idx - 1; 
        char nextChar = nxt < 0 ? ' ' : mem[nxt]; 
        if (nextChar == ' ' && isdigit(mem[idx])){ break; } 
        idx = nxt; 
    }
    for (int i = idx, len = mem.length(); i < len-1; i++){
        if (mem[i] == '_' && mem[i+1] == ' ') break;
        cnt++;
    }
    fileSize = cnt + 1; 
    return idx; 
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
            while(cnt--){ 
                res += getPacket(mxCnt, id) + '_'; 
            } 
            res += ' '; 
        }else{
            while (cnt--){ 
                for (int k = 0; k < mxCnt; k++) {
                    res += '.'; 
                } 
                res += '_'; 
            } 
            res += ' '; 
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
    //cout << mem << endl; 
    
    int rightFileSize = 0; 
    int l = 0, r = mem.length()-1; 
    
    while (l < r){
       int nr = findFileFromRight(r, rightFileSize, mem);
       int nl = findSpaceFromLeft(0, rightFileSize, mem);
    
       if (nl != -1 && nl < nr){
            for(int i = 0; i < rightFileSize; i++){
                swap(mem[nl+i], mem[nr+i]);
            }
       }
       r = nr - 1;
    }

    int len = mem.length(), id = 0, num = 0;
    ll answer = 0;
    //cout << mem << endl;

    for (int i = 0; i < len; i++){
        
        if (isdigit(mem[i])){
            num = (num * 10) + (mem[i] - '0');
        }else if (mem[i] == '_'){
            answer += (num * id);
            num = 0;
            id++;
        }
    }
    cout << answer << endl;
    return 0; 
}