#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    setIO("cownomics");
    int num_of_cows, gene_size;
    cin >> num_of_cows >> gene_size;

    vector<string> plain_cows(num_of_cows), spotted_cows(num_of_cows);

    for (int i = 0; i < num_of_cows; i++) { cin >> spotted_cows[i]; }
    for (int i = 0; i < num_of_cows; i++) { cin >> plain_cows[i]; }

    int ans = 0;
    for (int i = 0; i < gene_size; i++){
        set<char> spotted_gene;
        for (int r = 0; r < num_of_cows; r++){ spotted_gene.insert(spotted_cows[r][i]); }
        int cnt = spotted_gene.size();

        for (int r = 0; r < num_of_cows; r++){
            if (spotted_gene.count(plain_cows[r][i])){ spotted_gene.erase(plain_cows[r][i]); }
        }

        if (cnt == spotted_gene.size()) { ans++; }
    }
    cout << ans << endl;
    return 0;
}