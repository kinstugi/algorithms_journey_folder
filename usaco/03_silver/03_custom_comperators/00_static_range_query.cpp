#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 4e5 + 5;
ll prefix_sum[N], diff_array[N];

vector<pair<ll, ll>> queries, updates;
vector<ll> indices;

int get_new_index(int old_id){
    return lower_bound(indices.begin(), indices.end(), old_id) - indices.begin();
}

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    setIO();
    ll num_queries, num_updates, start, end, val;

    cin >> num_updates >> num_queries;

    for (int i = 0; i < num_updates; i++){
        cin >> start >> end >> val;
        indices.push_back(start);
        indices.push_back(end);
        updates.push_back({start, val});
        updates.push_back({end, -val});
    }

    for (int i = 0; i < num_queries; i++){
        cin >> start >> end;
        indices.push_back(start);
        indices.push_back(end);
        queries.push_back({start, end});
    }
    
    sort(indices.begin(), indices.end());
    indices.erase(unique(indices.begin(), indices.end()), indices.end());

    for (const auto &[id, val]: updates){ diff_array[get_new_index(id)+1] += val; }
    for (int i = 1; i <= indices.size(); i++) {  diff_array[i] += diff_array[i-1];  }

    for (int i = 1; i <= indices.size(); i++){
        prefix_sum[i] = prefix_sum[i-1] + diff_array[i] * (indices[i] - indices[i-1]);
    }

    for (const auto &[l, r]: queries){
        cout << prefix_sum[get_new_index(r)] - prefix_sum[get_new_index(l)] << endl;
    }
    return 0;
}