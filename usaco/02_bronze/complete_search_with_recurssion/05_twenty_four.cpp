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

// Helper function to perform operations and handle invalid cases.
ll helper(ll num1, ll num2, char op) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/': {
            // Division by zero or non-integer result is invalid.
            if (num2 == 0 || num1 % num2 != 0) { 
                return INT32_MIN; 
            }
            return num1 / num2;
        }
    }
    return INT32_MIN;
}

// Function to evaluate expressions with different operation orders.
ll evaluate(vector<ll>& nums, char op1, char op2, char op3) {
    // Case 1: ((num1 op1 num2) op2 num3) op3 num4
    ll res1 = helper(nums[0], nums[1], op1);
    if (res1 == INT32_MIN) return INT32_MIN; // Stop if invalid

    ll res2 = helper(res1, nums[2], op2);
    if (res2 == INT32_MIN) return INT32_MIN; // Stop if invalid

    ll final_res = helper(res2, nums[3], op3);
    if (final_res != INT32_MIN) return final_res; // If valid, return result
    
    // Case 2: (num1 op1 num2) op2 (num3 op3 num4)
    ll first = helper(nums[0], nums[1], op1);
    ll second = helper(nums[2], nums[3], op3);
    if (first != INT32_MIN && second != INT32_MIN) {
        return helper(first, second, op2);
    }
    
    return INT32_MIN; // Invalid result
}

int main() {
    ll n;
    vector<ll> hand(4);
    cin >> n;
    
    string operators = "*/+-";
    
    for (int i = 0; i < n; i++) {
        // Input the current hand
        for (int k = 0; k < 4; k++) { 
            cin >> hand[k]; 
        }
        
        sort(hand.begin(), hand.end());
        ll res = INT32_MIN;

        // Generate all permutations of the hand
        do {
            // Try all operator combinations
            for (char op1: operators) {
                for (char op2: operators) {
                    for (char op3: operators) {
                        ll eval_result = evaluate(hand, op1, op2, op3);
                        
                        // Only update result if it's valid and <= 24
                        if (eval_result != INT32_MIN && eval_result <= 24) {
                            res = max(res, eval_result);
                        }
                    }
                }
            }
        } while (next_permutation(hand.begin(), hand.end()));

        cout << res << endl;
    }
    
    return 0;
}
