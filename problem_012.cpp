/*
The sequence of triangle numbers is generated by adding the natural numbers. 
So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. 
The first ten terms would be:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

Let us list the factors of the first seven triangle numbers:

 1: 1
 3: 1,3
 6: 1,2,3,6
10: 1,2,5,10
15: 1,3,5,15
21: 1,3,7,21
28: 1,2,4,7,14,28
We can see that 28 is the first triangle number to have over five divisors.

What is the value of the first triangle number to have over five hundred divisors?
*/
#include <iostream>
#include <math.h>
using namespace std;

int n_min_divisors = 500;

long long int triangle_n(long long int index) {
	long long int result = index * (index + 1) / 2;
	return result;
}

int divisors_n(long long int n) {
	if (n == 1) {
		return 1;
	}
	else {
		int result = 0;
		int max_divisor = sqrt(n);
		for (int i = 1; i <= max_divisor; i++) {
			if (n % i == 0) {
				result += 2;
			}
		}
		if (max_divisor * max_divisor == n) {
			result -= 1;
		}
		return result;
	}

}

int main() {

	bool stop = false;
	long long int current_index = 1;
	long long int current_tri = 1;
	int current_n_divisors = 1;
	while (!stop) {
		current_index += 1;
		current_tri = triangle_n(current_index);
		current_n_divisors = divisors_n(current_tri);
		if (current_n_divisors > n_min_divisors) {
			stop = true;
		}
	}
	cout << "Index: " << current_index << endl;
	cout << "Triangular: " << current_tri << endl;
	cout << "Divisors: " << current_n_divisors << endl;
}