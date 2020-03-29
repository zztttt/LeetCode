int func(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	int mid = n / 2;
	return func(n / 2) + 1;
}