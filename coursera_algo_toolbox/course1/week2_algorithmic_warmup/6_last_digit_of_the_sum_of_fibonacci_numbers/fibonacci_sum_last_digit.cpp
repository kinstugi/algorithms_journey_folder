#include <iostream>
using ll = long long;
int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fib_sum(ll n){
	if (n <= 1) return n;
	ll a = 0, b = 1, sum = 1;
	
	for (ll i = 2; i <= n; ++i){
		ll c = ((a%10) + (b%10)) % 10;
		sum = (sum + c) % 10;
		a = b;
		b = c;
	}
	return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n);
	std::cout << fib_sum(n) << '\n';
}
