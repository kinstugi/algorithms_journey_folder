#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long fib_huge(long long n, long long m){
	if (n <= 1) return n;
	long long a = 0 , b = 1;
	for (long long i = 2; i <= n; ++i){
		long long c = ((a % m) + (b % m)) % m;
		a = b;
		b = c;
	}
	return b;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
	std::cout << fib_huge(n , m) << '\n';
}
