int main() {
	int n; cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int ret = 0;
	for (int i = n - 2; i >= 0; --i) {
		int cur = v[i];
		int right = v[i + 1];
		if (cur > right) {
			int t = (cur - 1) / right;
			int rest = cur - t * right;
			if (rest != 0)
				t++;
			v[i] = cur / t;
			ret += (t - 1);
		}
	}
	cout << ret << endl;
	return 0;
}