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
    setIO("rental");
    int num_cows, num_shops, num_neighbors;
    cin >> num_cows >> num_shops >> num_neighbors;
    
    vector<int> cows(num_cows);
    vector<int> neighbors(num_neighbors);
    vector<pair<int, int>> shop_orders;

    for (int i = 0; i < num_cows; i++){ cin >> cows[i]; }
    for (int i = 0; i < num_neighbors; i++){ cin >> shop_orders[i].second >> shop_orders[i].first; }
    for (int i = 0; i < num_neighbors; i++) { cin >> neighbors[i]; }

    sort(cows.begin(), cows.end(), greater<int>());
    sort(shop_orders.begin(), shop_orders.end(), greater<int>());
    sort(neighbors.begin(), neighbors.end(), greater<int>());

    int shop_at = 0, rent_at = 0, cow_at = 0;
    ll max_money = 0;

    while (cow_at < num_cows){
        
    }
    
    return 0;
}