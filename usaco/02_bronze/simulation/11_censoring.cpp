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
    setIO("censor");
    string full_sentence, censored_word;
    cin >> full_sentence >> censored_word;
    string res = "";
    int N = censored_word.size();

    for (char ch: full_sentence){
        while(res.size() >= N){
            if (res.substr(res.size() - N) == censored_word){
                for (int i = 0; i < N; i++) {res.pop_back(); }
            }else{
                break;
            }
        }
        res.push_back(ch);
    }
    cout << res << endl;
    return 0;
}