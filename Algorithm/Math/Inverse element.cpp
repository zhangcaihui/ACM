//Solution 1:
// when we used this method to calculate x / y % p, we also need x and p is coprime 
// Method 1: 	Extended Euclid
// Requires:	a and b is coprime
// Modify:  	x, y
// Effects: 	when the method is finished, x is a's inverse element about b.
// Return:  	gcd(a, b)
int ex_gcd(int a, int b, int &x, int &y) {
	int ret, tmp;
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ret = ex_gcd(b, a % b, x, y);
	tmp = x;
	x = y;
	y = tmp - a / b * y;
	return ret;
}


//Solution 2:
// when we used this method to calculate x / y % p, we also need x and p is coprime
// Method 2:	Quick Power
// Requires:	p is prime
// Modify:   	none
// Effects: 	return n's inverse element about p
// Return:  	n's inverse element about p
 
int quick_inverse(int n, int p) {
	int ret = 1;
	int exponent = p - 2;
	for (int i = exponent; i; i >>= 1, n = n * n % p) {
		if (i & 1) {
			ret = ret * n % p;
		}
	} 
	return ret;
}


//Solution 3:
// when we used this method to calculate x / y % p, we also need x and p is coprime
// Method 3:	Recursive to get i's inverse element
// Requires:	p is prime and p != 2
// Modify:  	inv[]
// Effects: 	inv[i] is i's inverse element about p;
int inv[N];
void get_inverse(int n, int p) {
	inv[1] = 1;
	for (int i = 2; i <= n; ++i) {
		inv[i] = (p - p / i) * inv[p % i] % p;
	}
}
